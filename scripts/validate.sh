#!/usr/bin/env bash
set -eu -o pipefail

readonly ROOT="$(realpath "$(dirname "$(realpath "$0")")"/..)"
readonly CHECK_COMMAND="g++ -fsyntax-only -Wall -Wextra -Wno-deprecated -std=c++17"
readonly FILE_MATCH="([a-zA-Z]*)\.[c|h]pp"

function main() {
  exitcode=0

  for file in "$ROOT"/*; do
    if [[ $file =~ $FILE_MATCH ]]; then
      echo -e "Checking file:\033[0;33m $(basename "$file") \033[0m"
      if ! eval "$CHECK_COMMAND $file"; then
        exitcode=1
      fi
    fi
  done

  if [[ $exitcode != 0 ]]; then
    echo "There are some problems!"
  fi

  exit $exitcode
}

main "$@"
