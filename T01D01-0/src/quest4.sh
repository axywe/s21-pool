proc=$(ps | grep ai_door_control.sh | grep /bin/bash)
num=${proc%ttys*}
kill $num
