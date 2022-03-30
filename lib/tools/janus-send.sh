#!/bin/bash

JANUSPATH=../janus-c-3.0.5/bin/

cd $JANUSPATH
exec ./janus-tx --config-file ../etc/txcfg_rawfile.ini --packet-cargo "$1"
