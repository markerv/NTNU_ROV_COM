#!/bin/bash

SDMSHPATH=/home/markerv/Documents/Bproject/sdmsh/
JANUSPATH=/home/markerv/Documents/Bproject/janus-c-3.0.5/


cd $JANUSPATH
exec ./janus-rx --config-file rxcfg.ini --verbose 1 --stream-driver raw --stream-driver-args myMessage.raw 2> myLog.txt

