
function build() {
    pushd $1
    mkdir build
    cd build
    cmake -G 'Unix Makefiles' ..
    make && make test
    popd
}

build samek

