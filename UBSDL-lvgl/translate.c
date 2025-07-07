Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
0x00005555555dad04 in deepseek_send_message (
    session=0xe8809ce9af98e698, 
    message=0x555557e5d580 <input> "hello", 
    prompt_tokens=0x555557e5d980 <prompt_tokens>, 
    completion_tokens=0x555557e5d984 <completion_tokens>, 
    total_tokens=0x555557e5d988 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:607
607	    struct APIResponse api_res = call_deepseek(session->api_key, message);
(gdb) bt
#0  0x00005555555dad04 in deepseek_send_message (
    session=0xe8809ce9af98e698, 
    message=0x555557e5d580 <input> "hello", 
    prompt_tokens=0x555557e5d980 <prompt_tokens>, 
    completion_tokens=0x555557e5d984 <completion_tokens>, 
    total_tokens=0x555557e5d988 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:607
#1  0x00005555555db09c in depmaintalk (e=0x7fffffffdb40)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:743
#2  0x00005555555d83d2 in ui_event_inputlogo (e=0x7fffffffdb40)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:731
#3  0x0000555555587ab7 in event_send_core (e=0x7fffffffdb40)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#4  0x000055555558684e in lv_event_send (
    obj=0x555557e42c00 <work_mem_int+24224>, 
    event_code=LV_EVENT_CLICKED, 
    param=0x555557e3eee8 <work_mem_int+8584>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:74
--Type <RET> for more, q to quit, c to continue without paging--

Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
0x00005555555dacb1 in deepseek_send_message (session=0x656b696c20642775, 
    message=0x555557e5d580 <input> "hellogood afternoonnice to meet uwhat is your name", prompt_tokens=0x555557e5d980 <prompt_tokens>, 
    completion_tokens=0x555557e5d984 <completion_tokens>, 
    total_tokens=0x555557e5d988 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:599
599	    if (!session || !session->api_key) {












	Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
0x00005555555dacb1 in deepseek_send_message (session=0x656b696c20642775,
    message=0x555557e5d580 <input> "hellogood afternoonnice to meet uwhat is your name", prompt_tokens=0x555557e5d980 <prompt_tokens>,
    completion_tokens=0x555557e5d984 <completion_tokens>,
    total_tokens=0x555557e5d988 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:599
599	    if (!session || !session->api_key) {








	[OSession pointer: 0x6569726620612074

Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
0x00005555555dacea in deepseek_send_message (session=0x6569726620612074, 
    message=0x555557e5d580 <input> "hellohellohello", 
    prompt_tokens=0x555557e5d980 <prompt_tokens>, 
    completion_tokens=0x555557e5d984 <completion_tokens>, 
    total_tokens=0x555557e5d988 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:602
602	        printf("API key: %s\n", session->api_key ? "VALID" : "NULL");
(gdb) 












	(gdb) bt
#0  0x00005555555dacea in deepseek_send_message (session=0x6569726620612074,
    message=0x555557e5d580 <input> "hellohellohello",
    prompt_tokens=0x555557e5d980 <prompt_tokens>,
    completion_tokens=0x555557e5d984 <completion_tokens>,
    total_tokens=0x555557e5d988 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:602
#1  0x00005555555db17b in depmaintalk (e=0x7fffffffda10)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:762
#2  0x00005555555d83f0 in ui_event_inputlogo (e=0x7fffffffda10)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:737
#3  0x0000555555587ab7 in event_send_core (e=0x7fffffffda10)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#4  0x000055555558684e in lv_event_send (
    obj=0x555557e42c00 <work_mem_int+24224>, event_code=LV_EVENT_CLICKED,
    param=0x555557e3eee8 <work_mem_int+8584>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:74
#5  0x000055555558b153 in indev_proc_release (
    proc=0x555557e3eef0 <work_mem_int+8592>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c:








Thread 1 "lvgl_sdl" received signal SIGSEGV, Segmentation fault.
0x00005555555dacea in deepseek_send_message (session=0x646e61202c726f66,
    message=0x555557e5d580 <input> "hellohellohellohellohello",
    prompt_tokens=0x555557e5d980 <prompt_tokens>,
    completion_tokens=0x555557e5d984 <completion_tokens>,
    total_tokens=0x555557e5d988 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:602
602	        printf("API key: %s\n", session->api_key ? "VALID" : "NULL");
(gdb)









(gdb) bt
#0  0x00005555555dacea in deepseek_send_message (session=0x646e61202c726f66, 
    message=0x555557e5d580 <input> "hellohellohellohellohello", 
    prompt_tokens=0x555557e5d980 <prompt_tokens>, 
    completion_tokens=0x555557e5d984 <completion_tokens>, 
    total_tokens=0x555557e5d988 <total_tokens>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:602
#1  0x00005555555db17b in depmaintalk (e=0x7fffffffda10)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:762
#2  0x00005555555d83f0 in ui_event_inputlogo (e=0x7fffffffda10)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:737
#3  0x0000555555587ab7 in event_send_core (e=0x7fffffffda10)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#4  0x000055555558684e in lv_event_send (
    obj=0x555557e42c00 <work_mem_int+24224>, event_code=LV_EVENT_CLICKED, 
    param=0x555557e3eee8 <work_mem_int+8584>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:74
#5  0x000055555558b153 in indev_proc_release (
    proc=0x555557e3eef0 <work_mem_int+8592>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_indev.c














    inputlogo被长按!
inputlogo被按下!
input = who are you hello nice to meet you
正在查询DeepSeek API...
调用前栈指针: 0x7fffffffd930
定位2...
Session pointer: 0x555558c2b640
API key: VALID
定位6...
调用前栈指针: 0x7fffffffd8b0
函数入口栈指针: 0x7fffffffd640
栈使用量: 7521750440437782825 字节
定位12...
定位13...
定14...
定位7...
[New Thread 0x7fffe6ba46c0 (LWP 136035)]
[Thread 0x7fffe6ba46c0 (LWP 136035) exited]
定位8...
定位9...
原始API响应: {"id":"f6590212-1983-4d9b-b9ab-20d03ea4e46f","object":"chat.completion","created":1751805012,"model":"deepseek-chat","choices":[{"index":0,"message":{"role":"assistant","content":"Hello! 👋 I’m DeepSeek Chat, your AI assistant created by **DeepSeek**. It’s so nice to meet you too! 😊  \n\nI’m here to help with answering questions, brainstorming ideas, providing advice, or just having a fun chat. Whether you need information, assistance with a task, or just want to talk, I’m happy to help!  \n\nHow can I assist you today? 🚀"},"logprobs":null,"finish_reason":"stop"}],"usage":{"prompt_tokens":11,"completion_tokens":92,"total_tokens":103,"prompt_tokens_details":{"cached_tokens":0},"prompt_cache_hit_tokens":0,"prompt_cache_miss_tokens":11},"system_fingerprint":"fp_8802369eaa_prod0623_fp8_kvcache"}
定位10...

