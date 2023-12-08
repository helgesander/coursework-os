#!/bin/bash

pid_first_server=$(pgrep first_server)
pid_second_server=$(pgrep second_server)

kill -2 $pid_first_server $pid_second_server