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

cd "/home/chris/indigo/rethink_ws/src/baxter_tools"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/chris/indigo/rethink_ws/install/lib/python2.7/dist-packages:/home/chris/indigo/rethink_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/chris/indigo/rethink_ws/build" \
    "/usr/bin/python" \
    "/home/chris/indigo/rethink_ws/src/baxter_tools/setup.py" \
    build --build-base "/home/chris/indigo/rethink_ws/build/baxter_tools" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/chris/indigo/rethink_ws/install" --install-scripts="/home/chris/indigo/rethink_ws/install/bin"
