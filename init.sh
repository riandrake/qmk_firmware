shopt -s expand_aliases

C:/Users/rian.drake/qmk_utils/activate_msys2.sh

keyboard() {
    if [ "$1" = "m60a" ]; then
        echo "wilba_tech/rama_works_m60_a"
    elif [ "$1" = "minivan" ]; then
        echo "thevankeyboards/minivan"
    elif [ "$1" = "iris" ]; then
        echo "keebio/iris"
    else
        echo "$1"
    fi
}

export_variables() {
    local util_dir=~/qmk_utils
    export PATH=$PATH:$util_dir
    export PATH=$PATH:$util_dir/dfu-programmer
    export PATH=$PATH:$util_dir/dfu-util-0.9-win64
    export PATH=$PATH:$util_dir/bootloadHID.2012-12-08/commandline
    export PATH=$PATH:$util_dir/flip/bin
    export PATH=$PATH:$util_dir/avr8-gnu-toolchain/bin
    export PATH=$PATH:$util_dir/gcc-arm-none-eabi/bin
    export PATH=$PATH:/mingw64/bin
	export PATH=$PATH:/c/Program\ Files\ \(x86\)/Vim/vim81
    export PATH=$PATH:/c/Program\ Files\/QMK\ Toolbox
}

build()
{
    local kb="$(keyboard "$*")"
	make $kb:rian
}

clean()
{
    local kb="$(keyboard "$*")"
    cd ../../
    make rian/$kb:default:clean
    cd keyboards/rian
}

edit()
{
    local kb="$(keyboard "$*")"
	gvim $kb/keymaps/default/* &
}

script()
{
    gvim init.sh &
}

toolbox()
{
	start qmk_toolbox
}

commit()
{
	git add .
    if [ $# -eq 0 ]
        then
            git commit -m "[no message]"
        else
            git commit -m "$1"
    fi
	git push
}

export_variables
toolbox

