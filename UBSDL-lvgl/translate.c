Program received signal SIGSEGV, Segmentation fault.
InitMessageHistory (hist=0x555559128f20)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:86
86	    hist->megcontent[0] = '\0'; // 初始化字符串
(gdb) bt
#0  InitMessageHistory (hist=0x555559128f20)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:86
#1  0x00005555555db2d5 in depmaintalk (e=0x7fffffffd980)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:745
#2  0x00005555555d8343 in ui_event_inputlogo (e=0x7fffffffd980)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:714
#3  0x0000555555587a97 in event_send_core (e=0x7fffffffd980)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#4  0x000055555558682e in lv_event_send (
    obj=0x555558359590 <work_mem_int+30416>, event_code=LV_EVENT_CLICKED, 
    param=0x555558354048 <work_mem_int+8584>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:74
#5  0x000055555558b133 in indev_proc_release (
    proc=0x555558354050 <work_mem_int+8592>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c:979
#6  0x00005555555898ed in indev_pointer_proc (
    i=0x555558354048 <work_mem_int+8584>, data=0x7fffffffda70)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c:383
#7  0x0000555555588ddc in lv_indev_read_timer_cb (
    timer=0x5555583540e0 <work_mem_int+8736>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c:101
#8  0x0000555555581686 in lv_timer_exec (
    timer=0x5555583540e0 <work_mem_int+8736>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/misc/lv_timer.c:313
#9  0x0000555555581234 in lv_timer_handler ()






    Program received signal SIGSEGV, Segmentation fault.
JudgeFull (meghistory=0x55555902d120)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:177
177	        if (meghistory->conversationMessage[i][0] == '\0') {
(gdb) bt
#0  JudgeFull (meghistory=0x55555902d120)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:177
#1  0x00005555555d9d67 in DeepseekAddMessage (meghistory=0x55555902d120,
    megcontent=0x555558372700 <input> "")
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:202
#2  0x00005555555db4f3 in depmaintalk (e=0x7fffffffd9e0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:867
#3  0x00005555555d8343 in ui_event_inputlogo (e=0x7fffffffd9e0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:714
#4  0x0000555555587a97 in event_send_core (e=0x7fffffffd9e0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#5  0x000055555558682e in lv_event_send (
    obj=0x555558359590 <work_mem_int+30416>, event_code=LV_EVENT_CLICKED,
    param=0x555558354048 <work_mem_int+8584>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:74
#6  0x000055555558b133 in indev_proc_release (
    proc=0x555558354050 <work_mem_int+8592>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c
    
    
    
    
    
    
    
    
    
    
    
    
    
    Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
0x00005555555e0893 in JudgeFull (meghistory=0x6574746163732a2a)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/MessageHistory.c:111
111	        if( meghistory->conversationMessage[i][0] == '\0' && i <= CONVERSATIONMEGCAP-1 )
(gdb) bt
#0  0x00005555555e0893 in JudgeFull (meghistory=0x6574746163732a2a)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/MessageHistory.c:111
#1  0x00005555555e0941 in DeepseekAddMessage (meghistory=0x6574746163732a2a, 
    megcontent=0x555558372fa0 <dpOut> "Here’s the current weather in **Guangzhou, China** (as of my latest data):  \n\n- **Temperature**: Around **28°C (82°F)**  \n- **Conditions**: Mostly **cloudy** with possible **scatte\n\366\001")
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/MessageHistory.c:136
#2  0x00005555555db26a in depmaintalk (e=0x7fffffffd9e0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:676
#3  0x00005555555d8363 in ui_event_inputlogo (e=0x7fffffffd9e0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:714
#4  0x0000555555587ab7 in event_send_core (e=0x7fffffffd9e0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#5  0x000055555558684e in lv_event_send (obj=0x555558359590 <work_mem_int+30416>, 
    event_code=LV_EVENT_CLICKED, param=0x555558354048 <work_mem_int+8584>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:74
#6  0x000055555558b153 in indev_proc_release (proc=0x555558354050 <work_mem_int+8592>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c:979
#7  0x000055555558990d in indev_pointer_proc (i=0x555558354048 <work_mem_int+8584>, 
    data=0x7fffffffdad0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c:383
#8  0x0000555555588dfc in lv_indev_read_timer_cb (
    timer=0x5555583540e0 <work_mem_int+8736>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c:101
#9  0x00005555555816a6 in lv_timer_exec (timer=0x5555583540e0 <work_mem_int+8736>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/misc/lv_timer.c:313
#10 0x0000555555581254 in lv_timer_handler ()
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/misc/lv_timer.c:109
#11 0x000055555555a995 in main ()
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/main.c:63
(gdb) 



















Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
Download failed: 无效的参数.  Continuing without source file ./string/../sysdeps/x86_64/multiarch/strlen-avx2.S.
__strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:76
warning: 76	../sysdeps/x86_64/multiarch/strlen-avx2.S: 没有那个文件或目录
(gdb) bt
#0  __strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:76
#1  0x00007ffff7a87bfd in __GI__IO_puts (str=0x0) at ./libio/ioputs.c:35
#2  0x00005555555da19e in call_deepseek (
    api_key=0x7fffffffedc6 "sk-6519dea3fbaa4bb98a7e3682c948afab",
    prompt=0x555558372700 <input> "hello")
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:305
#3  0x00005555555dae4b in deepseek_send_message (session=0x55555920e9e0,
    message=0x555558372700 <input> "hello",
    prompt_tokens=0x555558372f88 <prompt_tokens>,
    completion_tokens=0x555558372f8c <completion_tokens>,
    total_tokens=0x555558372f90 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:567
#4  0x00005555555db317 in depmaintalk (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:733
#5  0x00005555555d8372 in ui_event_inputlogo (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:712
#6  0x0000555555587ab7 in event_send_core (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#7  0x000055555558684e in lv_event_send (
    obj=0x555558359590 <work_mem_int+30416>, event_code=LV_EVENT_CLICKED,
    param=0x555558354048 <work_mem_int+8584>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:




















    Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
0x00005555555de3b6 in print_object (item=0x555559156ca0,
    output_buffer=0x7fffffffd840)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/cJSON.c:1815
1815	        if (!print_string_ptr((unsigned char*)current_item->string, output_buffer))
(gdb) bt
#0  0x00005555555de3b6 in print_object (item=0x555559156ca0,
    output_buffer=0x7fffffffd840)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/cJSON.c:1815
#1  0x00005555555dda3b in print_value (item=0x555559156ca0,
    output_buffer=0x7fffffffd840)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/cJSON.c:1484
#2  0x00005555555dd1cb in print (item=0x555559156ca0, format=1,
    hooks=0x555557f94720 <global_hooks>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/cJSON.c:1253
#3  0x00005555555dd322 in cJSON_Print (item=0x555559156ca0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/cJSON.c:1304
#4  0x00005555555db42b in depmaintalk (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:767
#5  0x00005555555d837e in ui_event_inputlogo (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:718
#6  0x0000555555587ab7 in event_send_core (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#7  0x000055555558684e in lv_event_send (
    obj=0x555558359590 <work_mem_int+30416>, event_code=LV_EVENT_CLICKED,
    param=0x555558354048 <work_mem_int+8584>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:




















    Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
Download failed: 无效的参数.  Continuing without source file ./string/../sysdeps/x86_64/multiarch/strlen-avx2.S.
__strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:76
warning: 76	../sysdeps/x86_64/multiarch/strlen-avx2.S: 没有那个文件或目录
(gdb) bt
#0  __strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:76
#1  0x00005555555da234 in call_deepseek (
    api_key=0x7fffffffedc6 "sk-6519dea3fbaa4bb98a7e3682c948afab",
    prompt=0x555558372700 <input> "hello")
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:339
#2  0x00005555555dae5f in deepseek_send_message (session=0x55555910c7a0,
    message=0x555558372700 <input> "hello",
    prompt_tokens=0x555558372f88 <prompt_tokens>,
    completion_tokens=0x555558372f8c <completion_tokens>,
    total_tokens=0x555558372f90 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:598
#3  0x00005555555db31f in depmaintalk (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:764
#4  0x00005555555d8348 in ui_event_inputlogo (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:725
#5  0x0000555555587a77 in event_send_core (e=0x7fffffffd9d0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#6  0x000055555558680e in lv_event_send (
    obj=0x555558359590 <work_mem_int+30416>, event_code=LV_EVENT_CLICKED,
--Type <RET> for more, q to quit, c to continue without paging--




malloc_consolidate(): unaligned fastbin chunk detected

Thread 1 "lvgl_sdl" received signal SIGABRT, Aborted.
Download failed: 无效的参数.  Continuing without source file ./nptl/./nptl/pthread_kill.c.
__pthread_kill_implementation (no_tid=0, signo=6, threadid=<optimized out>)
    at ./nptl/pthread_kill.c:44
warning: 44	./nptl/pthread_kill.c: 没有那个文件或目录
(gdb) bt
#0  __pthread_kill_implementation (no_tid=0, signo=6, threadid=<optimized out>)
    at ./nptl/pthread_kill.c:44
#1  __pthread_kill_internal (signo=6, threadid=<optimized out>)
    at ./nptl/pthread_kill.c:78
#2  __GI___pthread_kill (threadid=<optimized out>, signo=signo@entry=6)
    at ./nptl/pthread_kill.c:89
#3  0x00007ffff7a4527e in __GI_raise (sig=sig@entry=6)
    at ../sysdeps/posix/raise.c:26
#4  0x00007ffff7a288ff in __GI_abort () at ./stdlib/abort.c:79
#5  0x00007ffff7a297b6 in __libc_message_impl (
    fmt=fmt@entry=0x7ffff7bce8d7 "%s\n") at ../sysdeps/posix/libc_fatal.c:134
#6  0x00007ffff7aa8ff5 in malloc_printerr (
    str=str@entry=0x7ffff7bd18a0 "malloc_consolidate(): unaligned fastbin chunk detected") at ./malloc/malloc.c:5772
#7  0x00007ffff7aa9d4c in malloc_consolidate (
    av=av@entry=0x7ffff7c03ac0 <main_arena>) at ./malloc/malloc.c:4846
#8  0x00007ffff7aaba90 in _int_malloc (
    av=av@entry=0x7ffff7c03ac0 <main_arena>, bytes=bytes@entry=16385)
    at ./malloc/malloc.c:4041
#9  0x00007ffff7aad6f4 in __GI___libc_malloc (bytes=16385)
    at ./malloc/malloc.c:3336
#10 0x00007ffff7d6c1a0 in ?? () from /lib/x86_64-linux-gnu/libcurl.so.4
#11 0x00007ffff7d6e0e5 in curl_multi_perform ()














    【 input = hello 】
正在查询DeepSeek API...
strncat 拼接后字符串：hello
调用前栈指针: 0x7ffc9f7bca80
Session pointer: 0x62d393a4ca60
API key: VALID
调用前栈指针: 0x7ffc9f7bca00
[函数入口栈指针: 0x7ffc9f7bc7b0]
[栈使用量: 0 字节]
{
	"model":	"deepseek-chat",
	"max_tokens":	2000,
	"messages":	[{
			"role":	"user",
			"content":	""
		}, {
			"role":	"assistant",
			"content":	"你好！请问有什么我可以帮助你的吗？😊"
		}, {
			"role":	"user",
			"content":	"hello"
		}]
}
原始API响应: <html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>


--- API请求详情 ---
端点: https://api.deepseek.com/chat/completions
模型: deepseek-chat
提示: hello
状态码: 400
<API错误: HTTP 400>
原始响应: <html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>

<错误：【cJSON_parse】(错误码：0, 详情：Success)>
获取回复时出错
退出eventcode！

*-----------------------------------------*
*-----------------------------------------*
inputlogo被长按!
-inputlogo被按下!-
【 input = hello 】
正在查询DeepSeek API...
strncat 拼接后字符串：hellohello
调用前栈指针: 0x7ffc9f7bca80
Session pointer: 0x62d393a4ca60
API key: VALID
调用前栈指针: 0x7ffc9f7bca00
[函数入口栈指针: 0x7ffc9f7bc7b0]
[栈使用量: 0 字节]
{
	"model":	"deepseek-chat",
	"max_tokens":	2000,
	"messages":	[{
			"role":	"user",
			"content":	""
		}, {
			"role":	"assistant",
			"content":	"你好！请问有什么我可以帮助你的吗？😊"
		}, {
			"role":	"user",
			"content":	"hello"
		}, {
			"role":	"user",
			"content":	"hello"
		}]
}
原始API响应: <html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>


--- API请求详情 ---
端点: https://api.deepseek.com/chat/completions
模型: deepseek-chat
提示: hello
状态码: 400
<API错误: HTTP 400>
原始响应: <html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>

<错误：【cJSON_parse】(错误码：0, 详情：Success)>
获取回复时出错
退出eventcode！

*-----------------------------------------*


















q
^C
Thread 1 "lvgl_sdl" received signal SIGINT, Interrupt.
Download failed: 无效的参数.  Continuing without source file ./time/../sysdeps/unix/sysv/linux/clock_nanosleep.c.
0x00007ffff7aecadf in __GI___clock_nanosleep (clock_id=clock_id@entry=0,
    flags=flags@entry=0, req=req@entry=0x7fffffffdb30, rem=rem@entry=0x0)
    at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78
warning: 78	../sysdeps/unix/sysv/linux/clock_nanosleep.c: 没有那个文件或目录
(gdb) bt
#0  0x00007ffff7aecadf in __GI___clock_nanosleep (clock_id=clock_id@entry=0,
    flags=flags@entry=0, req=req@entry=0x7fffffffdb30, rem=rem@entry=0x0)
    at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78
#1  0x00007ffff7af9a27 in __GI___nanosleep (req=req@entry=0x7fffffffdb30,
    rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/nanosleep.c:25
#2  0x00007ffff7b2972c in usleep (useconds=<optimized out>)
    at ../sysdeps/posix/usleep.c:31
#3  0x000055555555a9bf in main ()
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/main.c:64








    malloc_consolidate(): unaligned fastbin chunk detected

Thread 1 "lvgl_sdl" received signal SIGABRT, Aborted.
Download failed: 无效的参数.  Continuing without source file ./nptl/./nptl/pthread_kill.c.
__pthread_kill_implementation (no_tid=0, signo=6, threadid=<optimized out>)
    at ./nptl/pthread_kill.c:44
warning: 44	./nptl/pthread_kill.c: 没有那个文件或目录
(gdb) bt
#0  __pthread_kill_implementation (no_tid=0, signo=6, threadid=<optimized out>)
    at ./nptl/pthread_kill.c:44
#1  __pthread_kill_internal (signo=6, threadid=<optimized out>)
    at ./nptl/pthread_kill.c:78
#2  __GI___pthread_kill (threadid=<optimized out>, signo=signo@entry=6)
    at ./nptl/pthread_kill.c:89
#3  0x00007ffff7a4527e in __GI_raise (sig=sig@entry=6)
    at ../sysdeps/posix/raise.c:26
#4  0x00007ffff7a288ff in __GI_abort () at ./stdlib/abort.c:79
#5  0x00007ffff7a297b6 in __libc_message_impl (
    fmt=fmt@entry=0x7ffff7bce8d7 "%s\n") at ../sysdeps/posix/libc_fatal.c:134
#6  0x00007ffff7aa8ff5 in malloc_printerr (
    str=str@entry=0x7ffff7bd18a0 "malloc_consolidate(): unaligned fastbin chunk detected") at ./malloc/malloc.c:5772
#7  0x00007ffff7aa9d4c in malloc_consolidate (
    av=av@entry=0x7ffff7c03ac0 <main_arena>) at ./malloc/malloc.c:4846
#8  0x00007ffff7aaba90 in _int_malloc (av=av@entry=0x7ffff7c03ac0 <main_arena>,
    bytes=bytes@entry=5328) at ./malloc/malloc.c:4041
#9  0x00007ffff7aae87e in __libc_calloc (n=<optimized out>,
    elem_size=<optimized out>) at ./malloc/malloc.c:3754
#10 0x00007ffff7d8c664 in ?? () from /lib/x86_64-linux-gnu/libcurl.so.4
#11 0x00007ffff7d3b630 in curl_easy_init ()
   from /lib/x86_64-linux-gnu/libcurl.so.4
--Type <RET> for more, q to quit, c to continue without paging--

