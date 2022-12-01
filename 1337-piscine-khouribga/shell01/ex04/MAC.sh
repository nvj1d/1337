#!/bin/bash
ifconfig | grep ether | cut -d ' ' -f2 | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}'
