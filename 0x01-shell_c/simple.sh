#!/bin/bash
echo "simple shell"
echo $BASH
name=my_script
echo $name
echo "Enter name :"
read name
echo "entered name, $name"
read -p 'Username : 'User_var
read -sp 'password : 'pass_var #/*silent*/
echo "Username : $user_var"
echo "password : $pass_var"
echo "Enter names :"
read -a names
echo "Names : $(names[0]), $(names[1])"
