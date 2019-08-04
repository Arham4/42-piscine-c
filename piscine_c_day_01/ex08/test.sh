FT_NBR1="\\\'?\"\\\"'\\"
FT_NBR2=rcrdmddd
echo $FT_NBR1 + $FT_NBR2 | tr "'" "0" | tr '\' '1' | tr '"' '2' | tr '?' '3' | 
tr '!' '4' | tr 'm' '0' | tr 'r' '1' | tr 'd' '2' | tr 'o' '3' | tr 'c' '4' |
bc -l | awk '{
	print("ibase=5;obase=D;"$0);
}' | bc | sed -e "s/10/e/g" | sed -e "s/11/m/g" | sed -e "s/12/f/g" | tr '0' 'g' | tr '1' 't' | tr '2' 'a' | tr '3' 'i' | tr '4' 'o' |
tr '5' ' ' | tr '6' 'l' | tr '7' 'u' | tr '8' 'S' | tr '9' 'n'
