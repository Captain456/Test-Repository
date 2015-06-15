#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/home/chris/jade/rethink_ws/src/baxter_interface"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/chris/jade/rethink_ws/install/lib/python2.7/dist-packages:/home/chris/jade/rethink_ws/build/baxter_interface/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/chris/jade/rethink_ws/build/baxter_interface" \
    "/usr/bin/python" \
    "/home/chris/jade/rethink_ws/src/baxter_interface/setup.py" \
    build --build-base "/home/chris/jade/rethink_ws/build/baxter_interface" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/chris/jade/rethink_ws/install" --install-scripts="/home/chris/jade/rethink_ws/install/bin"
