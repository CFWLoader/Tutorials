# About

In detached thread experiment, we set PTHREAD_CREATE_DETACHED to make the new thread can't join the process.<br/>
But it seem useless because it behaves like a normal multithreading program that<br/> all thread will exit when the process exit without waiting operation in main thread.<br/>
The most important interface is pthread_attr_set${stateCode}(thread_attr_t* attr, ${stateCodeDefine});<br/>
You can get state codes via command man the interface.<br/>
