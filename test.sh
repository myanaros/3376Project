make > /dev/null
echo -e "\nRunning with a single airfield"
./airsim 5 7 .5 .4 360 0 20
echo -e "\nRunning with four airfields"
./airsim 5 7 .0625 .05 360 0 20
make clean > /dev/null
