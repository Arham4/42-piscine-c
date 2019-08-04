find . -name "*.sh" -exec basename {} \; | sed -n 's/\.sh$//p' 
