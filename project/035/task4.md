
```SQL
SELECT id, home_type, if(has_internet and has_tv, price * 0.9) as price
from Rooms
```

