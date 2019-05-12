#!/bin/bash

cat << "INPUT" | $ED /totallynonexistentfile 2>&1
h
q
INPUT

(( $? == 0 )) || exit 1
