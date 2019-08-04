mv president.txt president.bak
trap "mv president.bak president.txt" EXIT
