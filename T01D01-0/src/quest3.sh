cp -r door_management_fi door_management_files
mkdir door_management_files/door_configuration
mkdir door_management_files/door_logs
mkdir door_management_files/door_map
 
cp door_management_files/door_*.conf door_management_files/door_configuration/
cp door_management_files/door_*.log door_management_files/door_logs/
cp door_management_files/door_map_1.1 door_management_files/door_map/
 
 
rm door_management_files/*.*
rm door_management_fi