UID=$(shell id -u)
GID=$(shell id -g)

profile.out: ./.build/bmk
	./.build/bmk
	gprof ./.build/bmk gmon.out > $@
	@echo "copy and paste the conent of bmk.cpp to https://quick-bench.com/:"
	@cat bmk.cpp

.build/CMakeCache.txt: CMakeLists.txt
	cmake -B.build .

.build/bmk: .build/CMakeCache.txt $(shell find . -name '*.cpp')
	(cd .build && make)

docker: Dockerfile docker-compose.yaml
	docker compose build

shell:
	docker compose run -u ${UID}:${GID} --rm -it dev

clean:
	-rm -rf .build *.out

# Experimental
profile.clean.out: profile.out clean.sed
	sed -f clean.sed $< > $@

