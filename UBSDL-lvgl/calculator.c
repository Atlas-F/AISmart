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
#include <string.h>
#include <stdbool.h>

#include "stack.h"
// #include "mywindow1/ui.h"

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

/* 按键全局变量 */
lv_obj_t * btn0;
lv_obj_t * btn1;
lv_obj_t * btn2;
lv_obj_t * btn3;
lv_obj_t * btn4;
lv_obj_t * btn5;
lv_obj_t * btn6;
lv_obj_t * btn7;
lv_obj_t * btn8;
lv_obj_t * btn9;
lv_obj_t * btnadd;
lv_obj_t * btnjian;
lv_obj_t * btncheng;
lv_obj_t * btnchu;
lv_obj_t * btndengyu;
lv_obj_t * btndelete;

/* 案件文本全局变量*/
lv_obj_t * label0;
lv_obj_t * label1;
lv_obj_t * label2;
lv_obj_t * label3;
lv_obj_t * label4;
lv_obj_t * label5;
lv_obj_t * label6;
lv_obj_t * label7;
lv_obj_t * label8;
lv_obj_t * label9;
lv_obj_t * labeladd;
lv_obj_t * labeljian;
lv_obj_t * labelcheng;
lv_obj_t * labelchu;
lv_obj_t * labeldengyu;
lv_obj_t * labeldelete;

/* 显示框*/
lv_obj_t * showarea;


int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int num5 = 0;
double result = 0;
int opeflag = 0;

char operator;
char operator1;
char operator2;
char operator3;
char dengyu;

double nums[5] = {0,0,0,0,0};
char ops[] = {'+', '+', '+', '+'};

/* 操作符标志，*/
bool operatorflag = false;
bool operatorflag1 = false;
bool operatorflag2 = false;
bool operatorflag3 = false;


void getinput(lv_event_t * e);
void getoperator(lv_event_t * e);
void calculator(lv_event_t * e);

/*********** */


// 全局变量声明
double numbers[5];    // 存储操作数
char operators[4];    // 存储运算符
int num_count = 0;    // 实际操作数数量
int op_count = 0;     // 实际运算符数量

// 计算表达式的函数
double calculate_expression() {
    // 首先处理乘除法
    for (int i = 0; i < op_count; i++) {
        if (operators[i] == '*' || operators[i] == '/') {
            double result;
            if (operators[i] == '*') {
                result = numbers[i] * numbers[i + 1];
            } else {
                // 检查除数是否为零
                if (numbers[i + 1] == 0) {
                    printf("错误：除数不能为零！\n");
                    return 0;
                }
                result = numbers[i] / numbers[i + 1];
            }
            
            // 将计算结果放回数组，并移动后续元素
            numbers[i] = result;
            for (int j = i + 1; j < num_count - 1; j++) {
                numbers[j] = numbers[j + 1];
            }
            
            // 移除已处理的运算符，并移动后续运算符
            for (int j = i; j < op_count - 1; j++) {
                operators[j] = operators[j + 1];
            }
            
            num_count--;
            op_count--;
            i--; // 由于数组已移动，需要重新检查当前位置
        }
    }
    
    // 然后处理加减法
    double result = numbers[0];
    for (int i = 0; i < op_count; i++) {
        if (operators[i] == '+') {
            result += numbers[i + 1];
        } else {
            result -= numbers[i + 1];
        }
    }
    
    return result;
}

// 初始化表达式的函数
void init_expression(double nums[], char ops[], int num_len, int op_len) {
    if (num_len > 5 || op_len > 4) {
        printf("错误：操作数不能超过5个，运算符不能超过4个！\n");
        return;
    }
    
    for (int i = 0; i < num_len; i++) {
        numbers[i] = nums[i];
    }
    
    for (int i = 0; i < op_len; i++) {
        if (ops[i] != '+' && ops[i] != '-' && ops[i] != '*' && ops[i] != '/') {
            printf("错误：不支持的运算符 %c！\n", ops[i]);
            return;
        }
        operators[i] = ops[i];
    }
    
    num_count = num_len;
    op_count = op_len;
}

/************** */




/*********************
 * @brief 获取按键输入
 * @param  e 
 *************************************************/
void getinput(lv_event_t * e)
{
    
    lv_event_code_t code = lv_event_get_code(e);  //获取事件
    lv_obj_t * ta = lv_event_get_target(e);  //获取焦点组件
    if( code == LV_EVENT_CLICKED )
    {
        int num = 0;
        char * ch;
        ch = malloc(4);
        strcpy(ch, lv_label_get_text(lv_obj_get_child(ta ,0)));
        num = atoi(ch);
        for( int i= 0; i < 1; i++ )
        {
            if( num >= 0 && num <= 9 )
            {
                lv_textarea_add_text(showarea, ch);
                if( operatorflag )
                {  
                    num2 = num2*10 + num;
                    printf("num2 = %d\n", num2);
                }else if( operatorflag1 )
                {
                    // operatorflag = ~operatorflag;
                    num3 = num3*10 + num;
                    printf("num3 = %d\n", num3);
                }
                else if( operatorflag2 )
                {
                    // operatorflag1 = ~operatorflag1;
                    num4 = num4*10 + num;
                    printf("num4 = %d\n", num4);
                }
                else if( operatorflag3 )
                {
                    // operatorflag2 = ~operatorflag2;
                    num5 = num5*10 + num;
                    printf("num5 = %d\n", num5);
                }
                else 
                {
                    num1 = num1*10 + num;
                    printf("num1 = %d\n", num1);

                }            
            }
            
        }

    }

}

/*********************
 * @brief 获取操作符
 * @param  e 
 *************************************************/
void getoperator(lv_event_t * e)
{

    lv_event_code_t code = lv_event_get_code(e);  //获取事件
    lv_obj_t * ta = lv_event_get_target(e);  //获取焦点组件
    if( code == LV_EVENT_CLICKED )
    {
        char * ope = malloc(4);
        strcpy(ope, lv_label_get_text(lv_obj_get_child(ta ,0)));
        lv_textarea_add_text(showarea, ope);
        switch( opeflag )
        {
            case 0:
                // printf("operatorflag = %d\n", operatorflag);
                operatorflag = !operatorflag;
                operator = *ope;
                printf("operator = %c\n", operator);

                numbers[0] = nums[0] = num1;
                ops[0] = operator;

                
                printf("operatorflag = %d\n", operatorflag);
                break;
            case 1:
                operatorflag = !operatorflag;
                operatorflag1 = !operatorflag1;
                operator1 = *ope;
                numbers[1] = nums[1] = num2;
                printf("operator1 = %c\n", operator1);
                ops[1] = operator1;

                break;
            case 2:
                operatorflag1 = !operatorflag1;
                operatorflag2 = !operatorflag2;
                operator2 = *ope;
                numbers[2] = nums[2] = num3;
                printf("operator2 = %c\n", operator2);
                ops[2] = operator2;

                break;
            case 3:
                operatorflag2 = !operatorflag2;
                operatorflag3 = !operatorflag3;
                operator3 = *ope;
                numbers[3] = nums[3] = num4;
                printf("operator3 = %c\n", operator3);
                ops[3] = operator3;
                
                // printf("operatorflag = %d\n", operatorflag);
                // printf("operatorflag1 = %d\n", operatorflag1);
                // printf("operatorflag2 = %d\n", operatorflag2);
                // printf("operatorflag3 = %d\n", operatorflag3);
                // operatorflag3 = !operatorflag3;
                break;
        }
        opeflag++;
    }


}


/*********************
 * @brief 计算结果
 * @param  e 
 *************************************************/
void calculator(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);  //获取事件
    lv_obj_t * ta = lv_event_get_target(e);  //获取焦点组件
    if( code == LV_EVENT_CLICKED )
    {
        char * deng = malloc(4);
        strcpy(deng, lv_label_get_text(lv_obj_get_child(ta ,0)));
        lv_textarea_add_text(showarea, deng);
        dengyu = *deng;

        numbers[4] = nums[4] = num5;


        for( int i= 0; i<5; i++ )
        {
            printf("numbers = %.3f\n", numbers[i]);
        }
        for( int i= 0; i<4; i++ )
        {
            printf("ops = %c\n", ops[i]);
        }

        init_expression(nums,ops, 5, 4);
        result = calculate_expression();

        char * res = malloc(8);
        sprintf(res, "%.3f", result );
        lv_textarea_add_text(showarea, res);
        printf("result = %.3f\n", result);
        
        result = 0;
    }
    operatorflag = ~operatorflag;
}


/*********************
 * @brief 按位清除
 *************************************************/
void deleteAll()
{
    num1 = 0;
    num2 = 0;
    num3 = 0;
    num4 = 0;
    num5 = 0;
    opeflag = 0;
    result = 0;
    operatorflag = false;
    operatorflag1 = false;
    operatorflag2 = false;
    operatorflag3 = false;
    lv_textarea_del_char(showarea);

}

/*********************
 * @brief 长按全部清除
 *************************************************/
void clearAll(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);  //获取事件
    lv_obj_t * ta = lv_event_get_target(e);  //获取焦点组件
    if( code == LV_EVENT_LONG_PRESSED )     // 长按按键的时间在哪里设置？
    {
        num1 = 0;
        num2 = 0;
        num3 = 0;
        num4 = 0;
        num5 = 0;
        opeflag = 0;
        result = 0;
        operatorflag = false;
        operatorflag1 = false;
        operatorflag2 = false;
        operatorflag3 = false;
        lv_textarea_set_text(showarea, "");
    }

}

/*********************
 * @brief 按键矩阵初始化
 *************************************************/
void calKeyBoard()
{
    static int16_t col_dsc[] = {75, 75, 75, 75,LV_GRID_TEMPLATE_LAST};
    static int16_t row_dsc[] = {50, 50, 50, 50, LV_GRID_TEMPLATE_LAST};

    /*Create a container with grid*/
    lv_obj_t * cont = lv_obj_create(lv_scr_act());
    lv_obj_set_style_grid_column_dsc_array(cont, col_dsc, 0);
    lv_obj_set_style_grid_row_dsc_array(cont, row_dsc, 0);
    lv_obj_set_size(cont, 400, 300);
    // lv_obj_set_pos(cont, )
    lv_obj_center(cont);
    lv_obj_set_layout(cont, LV_LAYOUT_GRID);

    showarea = lv_textarea_create(lv_scr_act());
    lv_obj_set_size(showarea, 400, 60);
    lv_obj_align(showarea, LV_ALIGN_TOP_MID, 0 ,15);
    lv_textarea_set_one_line(showarea, true);

    /* 创建样式并设置字体（假设 18 号字体已准备好） */
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, &lv_font_montserrat_20);  /* 关键操作：设置字体 */

    /* 将样式应用到文本区域的主部分（文本显示区域） */
    lv_obj_add_style(showarea, &style, LV_PART_MAIN);

    /* 设置初始文本 */
    // lv_textarea_set_text(showarea, "文本区域 (18px)");


    lv_obj_t * label;
    lv_obj_t * obj;

    uint32_t i;
    for(i = 0; i < 16; i++) {
        uint8_t col = i % 4;
        uint8_t row = i / 4;


        switch (i)
        {
        case 0 :
            btn0 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn0, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label0 = lv_label_create(btn0);
            lv_label_set_text(label0, "0");

            lv_obj_add_event_cb(btn0, getinput, LV_EVENT_CLICKED, NULL);


            break;
        case 1 :
            btn1 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn1, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label1 = lv_label_create(btn1);
            lv_label_set_text(label1, "1");
            lv_obj_add_event_cb(btn1, getinput, LV_EVENT_CLICKED, NULL);

            break;
        case 2 :
            btn2 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn2, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label2 = lv_label_create(btn2);
            lv_label_set_text(label2, "2");
            lv_obj_add_event_cb(btn2, getinput, LV_EVENT_CLICKED, NULL);
            break;
        case 3 :
            btn3 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn3, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label3 = lv_label_create(btn3);
            lv_label_set_text(label3, "3");
            lv_obj_add_event_cb(btn3, getinput, LV_EVENT_CLICKED, NULL);
            break;
        case 4 :
            btn4 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn4, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label4 = lv_label_create(btn4);
            lv_label_set_text(label4, "4");
            lv_obj_add_event_cb(btn4, getinput, LV_EVENT_CLICKED, NULL);
            break;
        case 5 :
            btn5 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn5, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label5 = lv_label_create(btn5);
            lv_label_set_text(label5, "5");
            lv_obj_add_event_cb(btn5, getinput, LV_EVENT_CLICKED, NULL);
            break;
        case 6 :
            btn6 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn6, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label6 = lv_label_create(btn6);
            lv_label_set_text(label6, "6");
            lv_obj_add_event_cb(btn6, getinput, LV_EVENT_CLICKED, NULL);
            break;
        case 7 :
            btn7 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn7, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label7 = lv_label_create(btn7);
            lv_label_set_text(label7, "7");
            lv_obj_add_event_cb(btn7, getinput, LV_EVENT_CLICKED, NULL);
            break;
        case 8 :
            btn8 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn8, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label8 = lv_label_create(btn8);
            lv_label_set_text(label8, "8");
            lv_obj_add_event_cb(btn8, getinput, LV_EVENT_CLICKED, NULL);
            break;
        case 9 :
            btn9 = lv_btn_create(cont);
            lv_obj_set_grid_cell(btn9, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            label9 = lv_label_create(btn9);
            lv_label_set_text(label9, "9");
            lv_obj_add_event_cb(btn9, getinput, LV_EVENT_CLICKED, NULL);
            break;
        case 10 :
            btnadd = lv_btn_create(cont);
            lv_obj_set_grid_cell(btnadd, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            labeladd = lv_label_create(btnadd);
            lv_label_set_text(labeladd, "+");
            lv_obj_add_event_cb(btnadd, getoperator, LV_EVENT_CLICKED, NULL);

            break;
        case 11 :
            btnjian = lv_btn_create(cont);
            lv_obj_set_grid_cell(btnjian, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            labeljian = lv_label_create(btnjian);
            lv_label_set_text(labeljian, "-");
            lv_obj_add_event_cb(btnjian, getoperator, LV_EVENT_CLICKED, NULL);
            break;
        case 12 :
            btncheng = lv_btn_create(cont);
            lv_obj_set_grid_cell(btncheng, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            labelcheng = lv_label_create(btncheng);
            lv_label_set_text(labelcheng, "*");
            lv_obj_add_event_cb(btncheng, getoperator, LV_EVENT_CLICKED, NULL);
            break;
        case 13 :
            btnchu = lv_btn_create(cont);
            lv_obj_set_grid_cell(btnchu, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            labelchu = lv_label_create(btnchu);
            lv_label_set_text(labelchu, "/");
            lv_obj_add_event_cb(btnchu, getoperator, LV_EVENT_CLICKED, NULL);
            break;
        case 14 :
            btndengyu = lv_btn_create(cont);
            lv_obj_set_grid_cell(btndengyu, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            labeldengyu = lv_label_create(btndengyu);
            lv_label_set_text(labeldengyu, "=");
            lv_obj_add_event_cb(btndengyu, calculator, LV_EVENT_CLICKED, NULL);
            break;
        case 15 :
            btndelete = lv_btn_create(cont);
            lv_obj_set_grid_cell(btndelete, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);
            labeldelete = lv_label_create(btndelete);
            lv_label_set_text(labeldelete, "delete");
            lv_obj_add_event_cb(btndelete, deleteAll, LV_EVENT_CLICKED, NULL);
            lv_obj_add_event_cb(btndelete, clearAll, LV_EVENT_LONG_PRESSED, NULL);
            break;
        default:
            break;
        }

        // lv_obj_center(label);

}


}



void jisuan()
{

}


int main(void)
{

    //初始化
    lvgl_init_framebuffer_ts();


    calKeyBoard();

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