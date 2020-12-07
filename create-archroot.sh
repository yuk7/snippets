mkdir -m 0755 -p install/var/{cache/pacman/pkg,lib/pacman,log}
mkdir -m 1777 -p install/tmp
mkdir -m 0555 -p iinstall/{sys,proc}
pacman --root install --config ./pacman.conf -Sy
pacman --root install --config ./pacman.conf -S base