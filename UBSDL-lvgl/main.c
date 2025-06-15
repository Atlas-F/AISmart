/*********************
 * @file main.c
 * @brief AiSmart 小智主程序 Ubuntu模拟器 X86架构
 * @author LFG (lfg@.com)
 * @version 1.0
 * @date 2025-06-12
 * 
 * @copyright Copyright (c) 2025  LFG
 * 
 *************************************************/
// cmake -DCMAKE_C_COMPILER=/usr/local/arm/5.4.0/usr/bin/arm-linux-gcc -DCMAKE_CXX_COMPILER=/usr/local/arm/5.4.0/usr/bin/arm-linux-g++ ..
#include <stdio.h>
#include "lv_conf.h"
#include <lv_drivers/sdl/sdl.h>
#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include <sys/time.h>
#include <lvgl/demos/lv_demos.h>
#include <unistd.h>
#include <stdlib.h>
#include "AiSmart/ui.h"
#include "AiSmart/ui_events.h"
#include <time.h>
// #include "AISmart.h"


#define  DISP_BUF_SIZE  800*480*4
void lvgl_init_framebuffer_ts();
#define USD_SDL 1

static lv_obj_t* kb = NULL;
static void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);  //获取事件
    lv_obj_t * ta = lv_event_get_target(e);  //获取焦点组件
    if(code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED) {
        /*Focus on the clicked text area*/
        if(kb != NULL) lv_keyboard_set_textarea(kb, ta);
    }
    else if(code == LV_EVENT_READY) {
        LV_LOG_USER("Ready, current text: %s", lv_textarea_get_text(ta));
    }
}





int main(void)
{

    //初始化
    lvgl_init_framebuffer_ts();
    



    ui_init();

    
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }
    return  0;
}

void lvgl_init_framebuffer_ts()
{
    /*LittlevGL init*/
    lv_init();
#if USD_SDL
    sdl_init();
#else
    //配置显示接口
    fbdev_init();
    //初始化输入接口
    evdev_init();
#endif
    //输入接口
    static lv_color_t buf[DISP_BUF_SIZE]; //显示缓冲区
    static lv_color_t buf1[DISP_BUF_SIZE]; //显示缓冲区
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, buf1, DISP_BUF_SIZE);

    //设置显示缓冲区属性
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
#if USE_SDL
    disp_drv.flush_cb = sdl_display_flush;
#else
    disp_drv.flush_cb   = fbdev_flush;
#endif
    disp_drv.hor_res    = 800;
    disp_drv.ver_res    = 480;
    lv_disp_drv_register(&disp_drv);


    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;  //设置输入事件类型
    //设置具体采集输入数据接口
#if USE_SDL
    indev_drv_1.read_cb = sdl_mouse_read;
#else
    indev_drv_1.read_cb = evdev_read;
#endif
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

}
/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }
    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}