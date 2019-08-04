if [ $# -eq 1 ]; then
	cat $1 | grep -i "Nicolas\tBauer" | awk '{print $6}' | awk -F'[^0-9]*' '$1'
fi