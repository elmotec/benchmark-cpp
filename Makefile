UID=$(shell id -u)
GID=$(shell id -g)

profile.clean.out: profile.out clean.sed
	sed -f clean.sed $< > $@

profile.out: ./.build/bmk
	./.build/bmk
	gprof ./.build/bmk gmon.out > $@

.build/CMakeCache.txt: CMakeLists.txt
	cmake -B.build .

./.build/bmk: .build/CMakeCache.txt
	(cd .build && make)

docker: Dockerfile docker-compose.yaml
	docker compose build

shell:
	docker compose run -u ${UID}:${GID} --rm -it dev

clean:
	-rm -rf .build *.out

.PHONY:
