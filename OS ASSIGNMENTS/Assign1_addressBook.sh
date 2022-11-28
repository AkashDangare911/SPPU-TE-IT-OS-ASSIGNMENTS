create()
{
	echo "Enter name of file "
	read ab

	if [ -e $ab ]
	then
		echo "File already exist.."
	else
		touch $ab
	fi
}

insert(){
	echo "Enter name of file "
	read ab

	opt="1"

	while [ $opt -ne "0" ]
	do
		echo "Enter id : "
        read id
        echo "Enter name : "
        read name
        echo "Enter address : "
        read address
        echo "$id $name $address" >> $ab
        echo "Press 0 to exit / 1 to continue "
		read opt
	done
}

display(){
	echo "Enter name of file "
	read ab

	if [ -e $ab ]
	then
		cat $ab
	else	
		echo "File not found..."
	fi
}

search(){
	echo "Enter name of file "
	read ab
	echo "Enter name to search : "
	read name

	result=$(grep -h $name $ab)

	if [ "$result" != 0 ]
	then 	
		echo $result
	else
		echo "Name not found..."
	fi
}

delete(){
	echo "Enter name of file "
	read ab
	echo "Enter name to delete : "
	read name

	grep -v $name $ab >>temp
	rm $ab
	mv temp $ab
}

modify(){
	echo "Enter name of book :"
	read ab
	echo "Enter name of person"
	read name
	echo "Enter new name of person"
	read newName

	sed s/"$newName"/"$name"/g $ab
}

while [ true ]
do

echo " "
echo "1) Create"
echo "2) Insert"
echo "3) Display"
echo "4) Search"
echo "5) Delete"
echo "6) Modify"
echo "7) Exit"
	read ch
	case $ch in
		1)create ;;
		2)insert ;;
		3)display;;
		4)search ;;
		5)delete ;;
		6)modify ;;
		7) exit  ;;
		*)"wrong input";;
	esac
done