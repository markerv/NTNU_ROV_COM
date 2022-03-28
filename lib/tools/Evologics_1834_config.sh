#!/bin/bash

SDMSHPATH=/home/markerv/Documents/Bproject/sdmsh/
JANUSPATH=/home/markerv/Documents/Bproject/janus-c-3.0.5/

$SDMSHPATH./sdmsh 189 -e "stop;config 30 0 3 0"
$SDMSHPATH./sdmsh 198 -e "stop;config 30 0 3 0"