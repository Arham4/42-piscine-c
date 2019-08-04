ifconfig | grep inet | grep broadcast | awk '{print($2)}' | awk 'END{
	if (NR == 0) { 
		print("I am lost!") 
	} else { 
		print($0) 
	}
}'