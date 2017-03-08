set -ue
function build() {
    pushd $1
    rm -rf build
    mkdir build
    cd build
    cmake -G 'Unix Makefiles' ..
    make && make test
    popd
}

build samek
build weirich
