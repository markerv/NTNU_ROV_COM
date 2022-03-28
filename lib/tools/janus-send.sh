#!/bin/bash

SDMSHPATH=/home/markerv/Documents/Bproject/sdmsh/
JANUSPATH=/home/markerv/Documents/Bproject/janus-c-3.0.5/


cd $JANUSPATH
exec ./janus-tx --config-file txcfg_rawfile.ini --packet-cargo "$1"
