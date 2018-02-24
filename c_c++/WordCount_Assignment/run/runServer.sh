
DATE=$(date +%d-%m-%y_%I-%M-%S)
../bin/serverApp | tee -a "../logs/serverApp-$DATE.log"
