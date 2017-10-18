echo "Test start"

count=0

while [ $count -ne 10 ]
do
	echo "Test iteration: "
	echo "$count"
	echo "\n"

	res=`mq.sh run -c "end of test" -l output -s haswell4 -f images/kernel-ia32-pc99 -f images/sel4test-driver-image-ia32-pc99`

	echo "$res" | egrep "COLLECTION" >> temp

	count=$((count + 1))

done

echo "Test end\n"

