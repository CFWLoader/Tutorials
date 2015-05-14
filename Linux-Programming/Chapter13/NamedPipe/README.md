# About

The limit length of FIFO usually is 4K bytes.<br/>
O_NONBLOCK flag:<br/>
When it comes to read call, 0 byte will be return if programs read a empty, non-blocking FIFO.<br/>
An error will be return if program calls a write operation of non-blocking FIFO when the FIFO hasn't the request of reading.<br/>
