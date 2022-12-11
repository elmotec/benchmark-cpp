UID=$(shell id -u)
GID=$(shell id -g)

test: build
	./.build/bmk

configure: CMakeLists.txt
	cmake -B.build .

build:
	(cd .build && make)

docker: Dockerfile
	docker build .

shell:
	docker compose run -u ${UID}:${GID} --rm -it dev

