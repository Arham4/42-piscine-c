cat /etc/passwd | awk '{
	if (NR % 2 == 0 && substr($0, 0, 1) != "#") {
		print $0
	}
}' | awk -F':' -v ftLine1="$FT_LINE1" -v ftLine2="$FT_LINE2"  '
function reverse(s, r) {
	for (i=length(s); i > 0; i--) { 
		r = r substr(s, i, 1);
	}
	return r
}
{
	if (NR >= ftLine1 && NR <= ftLine2) {
		print $1
	}
}' | sort -r | awk -v ORS=', ' '1' | awk '{
	print(substr($0, 0, length($0) - 3)".")
}'

