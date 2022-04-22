const express = require('express');
const app = express();
app.use(express.static(__dirname + "/public"));
const server = app.listen(80, "192.168.1.98");
const io = require('socket.io')(server, {
  cors: {
   origin: "*",
   methods: ["GET", "POST"],
   transports: ["websocket", "polling"],
   credentials: true,
  },
   allowEIO3: true,
  });

io.on('connection', function (socket)
{ //2
  socket.on('Temperature', function (data)
  { 
    console.log(data);
  });
  socket.on('Humidity', function (data)
  { 
    console.log(data);
  });
  socket.on('rain', function (data)
  { 
    console.log(data);
  });
  console.log("connected");
});

