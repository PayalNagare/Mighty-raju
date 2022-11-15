
#!/bin/sh
	
	print_list() {
	  reset
	
	  echo "1 - Search Address Book"
	  echo "2 - Add an Address Book entry"
	  echo "3 - Remove an Address Book entry"
	  echo "4 - For quit, press 4, goodbye..."
	
	  echo "Select the number of your choice on the list, or quit by pressing q"
	}
	
	read_record() {
	
	  RECORD=$1
	  ID=$(nl address.txt | grep -w $RECORD | awk '{print $2}')
	  NAME=$(nl address.txt | grep -w $RECORD | awk '{print $3}')
	  PHONE=$(nl address.txt | grep -w $RECORD | awk '{print $4}')
	
	  echo "Id: $ID , Name: $NAME , Phone: $PHONE"
	}
	
	insert_record() {
	  echo "Please Enter Id"
	  read ID
	  echo "Please Enter Name "
	  read NAME
	  echo "Please Enter Phone Number "
	  read PHONE 
	  echo "Adding Address Book Entry..."
	  echo "$ID $NAME $PHONE" >> address.txt
	  echo "Data Inserted!"
	}
	
	remove_record() {
	  DATA=$1
	  echo "Removing Address Book Entry"
	  sed -i "/$DATA/d" address.txt
	}
	
	go_back() {
	  echo "For Going Back To Main Menu Press m, For Quit Press q"
	
	  read CHOICE_MENU
	  if [ $CHOICE_MENU = "m" ]; then
	    print_list
	    read CHOICE
	    elif [ $CHOICE_MENU = "q" ]; then
	      exit 0
	    else 
	      echo "The Command You Typed is Not Correct, for Main Menu Press m, for Quit Type q"
	  fi
	}
	
	echo "Welcome to Addressbook..."
	
	print_list
	
	read CHOICE
	
	while [ $CHOICE -ne 4 ]
	do
	  if [ $CHOICE -eq 1 ]; then
	    echo "Please Enter Either Id,Name or Phone Number"
	    read QUERY
	    read_record $QUERY
	    go_back
	    elif [ $CHOICE -eq 2 ]; then
	      insert_record
	      go_back
	    elif [ $CHOICE -eq 3 ]; then
	      echo "Please Enter Either Id,Name or Phone Number of user that you want to remove"
	      read USER
	      remove_record $USER
	      go_back
	    else 
	      exit 0
	  fi
	done
