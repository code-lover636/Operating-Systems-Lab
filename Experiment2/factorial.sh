# Program to print factorial of a number

read -p "Enter a number: " num

fact=1
i=1

while [ $i -le $num ]
do
  fact=$((fact * i))
  i=$((i + 1)) 
done

echo Factorial of $num is $fact.
