#!/usr/bin/env bash
set -eu -o pipefail

readonly CHECK_COMMAND="g++ -fsyntax-only -Wall -Wextra -Wno-deprecated -std=c++17"

function main() {
  exitcode=0

#  if ! eval "$CHECK_COMMAND Api.hpp"; then
#    exitcode=1
#  fi
#
#  if [[ $exitcode != 0 ]]; then
#    echo "There are some problems!"
#  fi

  echo "Don't check"

  exit $exitcode
}

main "$@"
