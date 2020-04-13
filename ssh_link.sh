#!/bin/bash
PS3="Select you while exec Menu?"
if [[ -z $1 ]];then  #有严格的空格控制
    echo -e "\033[36mUsage $0 command,example{bash $0 login_name}\033[0m"
    exit
fi
select i in "49.233.64.251" "123.56.173.77"
do
    case $i in
    	49.233.64.251)
    	    echo " wait ssh 49.233.64.251..."
    	    ssh $1@$i
    	    ;;
    	123.56.173.77)
    	    echo "wait ssh 123.56.173.77"
    	    ssh -p 1025 $1@$i
    	    ;;
    esac  
done

