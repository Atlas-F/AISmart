// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void floatout_Animation(lv_obj_t * TargetObject, int delay);
void floatoutlabel_Animation(lv_obj_t * TargetObject, int delay);


// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
void ui_event_Screen1(lv_event_t * e);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_circle1;
lv_obj_t * ui_Container1;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Image5;
lv_obj_t * ui_Image6;
lv_obj_t * ui_Image7;
lv_obj_t * ui_Image8;
lv_obj_t * ui_Image9;
lv_obj_t * ui_Image10;
lv_obj_t * ui_Image11;
lv_obj_t * ui_Image12;
lv_obj_t * ui_Image13;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Image14;
void ui_event_time(lv_event_t * e);
lv_obj_t * ui_time;
void ui_event_date(lv_event_t * e);
lv_obj_t * ui_date;
void ui_event_Oneto2(lv_event_t * e);
lv_obj_t * ui_Oneto2;
lv_obj_t * ui_Label3;
void ui_event_Oneto4(lv_event_t * e);
lv_obj_t * ui_Oneto4;
lv_obj_t * ui_Label5;


// SCREEN: ui_Screen4
void ui_Screen4_screen_init(void);
void ui_event_Screen4(lv_event_t * e);
lv_obj_t * ui_Screen4;
void ui_event_time2(lv_event_t * e);
lv_obj_t * ui_time2;
void ui_event_date2(lv_event_t * e);
lv_obj_t * ui_date2;
lv_obj_t * ui_circle4;
void ui_event_fourTo2(lv_event_t * e);
lv_obj_t * ui_fourTo2;
lv_obj_t * ui_Label11;
void ui_event_fourTo3(lv_event_t * e);
lv_obj_t * ui_fourTo3;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Image15;
lv_obj_t * ui_Image16;
lv_obj_t * ui_Image17;


// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
void ui_event_Screen2(lv_event_t * e);
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Label13;
lv_obj_t * ui_circle2;
void ui_event_to1(lv_event_t * e);
lv_obj_t * ui_to1;
lv_obj_t * ui_Label4;
void ui_event_to3(lv_event_t * e);
lv_obj_t * ui_to3;
void ui_event_Label7(lv_event_t * e);
lv_obj_t * ui_Label7;
lv_obj_t * ui_Container2;
lv_obj_t * ui_AIPanel;
lv_obj_t * ui_AILabel;
void ui_event_humanPanel(lv_event_t * e);
lv_obj_t * ui_humanPanel;
lv_obj_t * ui_humanLabel;
lv_obj_t * ui_Image51;
lv_obj_t * ui_Image52;


// SCREEN: ui_Screen3
void ui_Screen3_screen_init(void);
void ui_event_Screen3(lv_event_t * e);
lv_obj_t * ui_Screen3;
lv_obj_t * ui_Label2;
lv_obj_t * ui_circle;
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
void ui_event_Label6(lv_event_t * e);
lv_obj_t * ui_Label6;
void ui_event_Button7(lv_event_t * e);
lv_obj_t * ui_Button7;
void ui_event_Label9(lv_event_t * e);
lv_obj_t * ui_Label9;
lv_obj_t * ui_Container3;
lv_obj_t * ui_Image18;
lv_obj_t * ui_Image19;
lv_obj_t * ui_Image20;
lv_obj_t * ui_Image21;
lv_obj_t * ui_Image22;
lv_obj_t * ui_Image23;
lv_obj_t * ui_Image24;
lv_obj_t * ui_Image25;
lv_obj_t * ui_Image26;
lv_obj_t * ui_Image27;
lv_obj_t * ui_Image28;
lv_obj_t * ui_Image29;
lv_obj_t * ui_Image30;
lv_obj_t * ui_Image31;
lv_obj_t * ui_Image32;
lv_obj_t * ui_Image33;
lv_obj_t * ui_Image34;


// SCREEN: ui_Screen5
void ui_Screen5_screen_init(void);
void ui_event_Screen5(lv_event_t * e);
lv_obj_t * ui_Screen5;
lv_obj_t * ui_Label1;
lv_obj_t * ui_circle3;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
void ui_event_Label8(lv_event_t * e);
lv_obj_t * ui_Label8;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
void ui_event_Label10(lv_event_t * e);
lv_obj_t * ui_Label10;
lv_obj_t * ui_Container4;
lv_obj_t * ui_Image35;
lv_obj_t * ui_Image36;
lv_obj_t * ui_Image37;
lv_obj_t * ui_Image38;
lv_obj_t * ui_Image39;
lv_obj_t * ui_Image40;
lv_obj_t * ui_Image41;
lv_obj_t * ui_Image42;
lv_obj_t * ui_Image43;
lv_obj_t * ui_Image44;
lv_obj_t * ui_Image45;
lv_obj_t * ui_Image46;
lv_obj_t * ui_Image47;
lv_obj_t * ui_Image49;
lv_obj_t * ui_Image48;
lv_obj_t * ui_Image50;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_1771576097[3] = {&ui_img_525561802, &ui_img_1758698815, &ui_img_1758700865};
const lv_img_dsc_t * ui_imgset_214588207[1] = {&ui_img_691945150};
const lv_img_dsc_t * ui_imgset_709041957[1] = {&ui_img_921266886};
const lv_img_dsc_t * ui_imgset_989931824[1] = {&ui_img_838590808};
const lv_img_dsc_t * ui_imgset_1049962433[1] = {&ui_img_6017182};
const lv_img_dsc_t * ui_imgset_2089841342[1] = {&ui_img_189052461};
const lv_img_dsc_t * ui_imgset_22131592[1] = {&ui_img_1800458682};
const lv_img_dsc_t * ui_imgset_744070797[1] = {&ui_img_1488135120};
const lv_img_dsc_t * ui_imgset_1599751486[1] = {&ui_img_873017022};
const lv_img_dsc_t * ui_imgset_922892278[1] = {&ui_img_64789106};
const lv_img_dsc_t * ui_imgset_86048932[1] = {&ui_img_15388586};
const lv_img_dsc_t * ui_imgset_512339140[1] = {&ui_img_413235124};
const lv_img_dsc_t * ui_imgset_947524131[1] = {&ui_img_1447691688};
const lv_img_dsc_t * ui_imgset_1040305335[1] = {&ui_img_865156645};
const lv_img_dsc_t * ui_imgset_568213453[1] = {&ui_img_986324200};
const lv_img_dsc_t * ui_imgset_2062000692[1] = {&ui_img_719381313};
const lv_img_dsc_t * ui_imgset_1535898763[1] = {&ui_img_701452542};
const lv_img_dsc_t * ui_imgset_961691810[1] = {&ui_img_1182216894};
const lv_img_dsc_t * ui_imgset_201386671[1] = {&ui_img_743825838};
const lv_img_dsc_t * ui_imgset_2124320370[1] = {&ui_img_1040098182};
const lv_img_dsc_t * ui_imgset_804880325[1] = {&ui_img_213109427};
const lv_img_dsc_t * ui_imgset_682780149[1] = {&ui_img_1006453824};
const lv_img_dsc_t * ui_imgset_2020681219[1] = {&ui_img_2026381252};
const lv_img_dsc_t * ui_imgset_155023251[1] = {&ui_img_1628148309};
const lv_img_dsc_t * ui_imgset_569646602[1] = {&ui_img_2084888120};
const lv_img_dsc_t * ui_imgset_ufo_[1] = {&ui_img_1395808306};
const lv_img_dsc_t * ui_imgset_1391766876[1] = {&ui_img_190977669};
const lv_img_dsc_t * ui_imgset_695157105[1] = {&ui_img_1720058713};
const lv_img_dsc_t * ui_imgset_2080754753[1] = {&ui_img_1220561086};
const lv_img_dsc_t * ui_imgset_1066521673[1] = {&ui_img_1932583977};
const lv_img_dsc_t * ui_imgset_512650209[1] = {&ui_img_721922142};
const lv_img_dsc_t * ui_imgset_326097338[1] = {&ui_img_1317392200};
const lv_img_dsc_t * ui_imgset_1864878729[1] = {&ui_img_328345682};
const lv_img_dsc_t * ui_imgset_1865318056[2] = {&ui_img_537163071, &ui_img_1345017118};
const lv_img_dsc_t * ui_imgset_1912969485[1] = {&ui_img_338008226};
const lv_img_dsc_t * ui_imgset_1864067694[1] = {&ui_img_1651021565};
const lv_img_dsc_t * ui_imgset_1862200589[1] = {&ui_img_188625264};
const lv_img_dsc_t * ui_imgset_1865343683[1] = {&ui_img_768535410};
const lv_img_dsc_t * ui_imgset_326097331[1] = {&ui_img_1874934912};
const lv_img_dsc_t * ui_imgset_149496853[1] = {&ui_img_796891563};
const lv_img_dsc_t * ui_imgset_1846812418[1] = {&ui_img_60263710};
const lv_img_dsc_t * ui_imgset_777841223[1] = {&ui_img_2103162353};
const lv_img_dsc_t * ui_imgset_1005280022[2] = {&ui_img_1195015344, &ui_img_1970916912};
const lv_img_dsc_t * ui_imgset_1003437511[1] = {&ui_img_120716944};
const lv_img_dsc_t * ui_imgset_1052751460[1] = {&ui_img_520820240};
const lv_img_dsc_t * ui_imgset_1006771218[1] = {&ui_img_409892641};
const lv_img_dsc_t * ui_imgset_1878277480[1] = {&ui_img_1106867240};
const lv_img_dsc_t * ui_imgset_2062479423[1] = {&ui_img_253109117};
const lv_img_dsc_t * ui_imgset_1515521711[1] = {&ui_img_758318489};
const lv_img_dsc_t * ui_imgset_1605037928[1] = {&ui_img_819928086};
const lv_img_dsc_t * ui_imgset_1617568496[1] = {&ui_img_154984886};
const lv_img_dsc_t * ui_imgset_605000656[1] = {&ui_img_1951583080};
const lv_img_dsc_t * ui_imgset_1826645905[1] = {&ui_img_1186072952};
const lv_img_dsc_t * ui_imgset_1696964721[1] = {&ui_img_1143713160};
const lv_img_dsc_t * ui_imgset_1182807109[1] = {&ui_img_396379797};
const lv_img_dsc_t * ui_imgset_1604853874[1] = {&ui_img_1433976870};
const lv_img_dsc_t * ui_imgset_1604825513[1] = {&ui_img_105594312};
const lv_img_dsc_t * ui_imgset_1128402848[1] = {&ui_img_754698310};
const lv_img_dsc_t * ui_imgset_1603584775[1] = {&ui_img_1250489853};
const lv_img_dsc_t * ui_imgset_75155151[1] = {&ui_img_647165550};
const lv_img_dsc_t * ui_imgset_2062787331[1] = {&ui_img_918736298};
const lv_img_dsc_t * ui_imgset_935483818[1] = {&ui_img_2024978968};
const lv_img_dsc_t * ui_imgset_989582740[1] = {&ui_img_1251777188};
const lv_img_dsc_t * ui_imgset_494656469[1] = {&ui_img_193771503};
const lv_img_dsc_t * ui_imgset_551694890[1] = {&ui_img_1072915872};
const lv_img_dsc_t * ui_imgset_1576399261[1] = {&ui_img_1997765350};
const lv_img_dsc_t * ui_imgset_249373986[1] = {&ui_img_1946132634};
const lv_img_dsc_t * ui_imgset_353316134[1] = {&ui_img_1673239870};
const lv_img_dsc_t * ui_imgset_1866267088[1] = {&ui_img_945703623};
const lv_img_dsc_t * ui_imgset_1333008944[1] = {&ui_img_1221264709};
const lv_img_dsc_t * ui_imgset_164363633[1] = {&ui_img_177437335};
const lv_img_dsc_t * ui_imgset_712057299[1] = {&ui_img_748560880};
const lv_img_dsc_t * ui_imgset_210256595[1] = {&ui_img_106759925};
const lv_img_dsc_t * ui_imgset_36883044[1] = {&ui_img_1613165469};
const lv_img_dsc_t * ui_imgset_1604703926[1] = {&ui_img_1627204797};
const lv_img_dsc_t * ui_imgset_1143617370[1] = {&ui_img_1651094022};
const lv_img_dsc_t * ui_imgset_2109214601[1] = {&ui_img_1863416723};
const lv_img_dsc_t * ui_imgset_1576151876[1] = {&ui_img_201494986};
const lv_img_dsc_t * ui_imgset_1628821516[2] = {&ui_img_1273346190, &ui_img_261042028};
const lv_img_dsc_t * ui_imgset_638970662[1] = {&ui_img_1579771612};
const lv_img_dsc_t * ui_imgset_384275185[1] = {&ui_img_449276547};
const lv_img_dsc_t * ui_imgset_1062921657[1] = {&ui_img_1558633752};
const lv_img_dsc_t * ui_imgset_1184325011[1] = {&ui_img_1779534644};
const lv_img_dsc_t * ui_imgset_114483616[1] = {&ui_img_1850222669};
const lv_img_dsc_t * ui_imgset_2065651781[1] = {&ui_img_520288613};
const lv_img_dsc_t * ui_imgset_2105151801[1] = {&ui_img_2130913025};
const lv_img_dsc_t * ui_imgset_2073622389[1] = {&ui_img_1810507611};
const lv_img_dsc_t * ui_imgset_1485504554[1] = {&ui_img_1042948001};
const lv_img_dsc_t * ui_imgset_230446316[1] = {&ui_img_878326522};
const lv_img_dsc_t * ui_imgset_1865237994[1] = {&ui_img_2100201431};
const lv_img_dsc_t * ui_imgset_2105266013[1] = {&ui_img_489599133};
const lv_img_dsc_t * ui_imgset_227581326[1] = {&ui_img_1887742475};
const lv_img_dsc_t * ui_imgset_561221881[1] = {&ui_img_1114756079};
const lv_img_dsc_t * ui_imgset_1484167716[1] = {&ui_img_440466655};
const lv_img_dsc_t * ui_imgset_1794743158[1] = {&ui_img_457596404};
const lv_img_dsc_t * ui_imgset_271528331[1] = {&ui_img_1442695620};
const lv_img_dsc_t * ui_imgset_68938883[1] = {&ui_img_410336698};
const lv_img_dsc_t * ui_imgset_1865069313[1] = {&ui_img_1521996747};
const lv_img_dsc_t * ui_imgset_448800592[1] = {&ui_img_2144570017};
const lv_img_dsc_t * ui_imgset_2145992433[1] = {&ui_img_169773555};
const lv_img_dsc_t * ui_imgset_810232795[1] = {&ui_img_642449591};
const lv_img_dsc_t * ui_imgset_1381333491[1] = {&ui_img_1409127908};
const lv_img_dsc_t * ui_imgset_2096038929[1] = {&ui_img_836835141};
const lv_img_dsc_t * ui_imgset_1494790765[1] = {&ui_img_590844277};
const lv_img_dsc_t * ui_imgset_1541430191[1] = {&ui_img_1305061770};
const lv_img_dsc_t * ui_imgset_396852007[1] = {&ui_img_1646327931};
const lv_img_dsc_t * ui_imgset_983897653[1] = {&ui_img_1804492491};
const lv_img_dsc_t * ui_imgset_994527919[1] = {&ui_img_1078335801};
const lv_img_dsc_t * ui_imgset_1351718651[1] = {&ui_img_155258266};
const lv_img_dsc_t * ui_imgset_1155208108[1] = {&ui_img_1179136265};
const lv_img_dsc_t * ui_imgset_1965541761[1] = {&ui_img_1152444760};
const lv_img_dsc_t * ui_imgset_63792652[1] = {&ui_img_1274767758};
const lv_img_dsc_t * ui_imgset_1940061365[1] = {&ui_img_998280680};
const lv_img_dsc_t * ui_imgset_972635809[1] = {&ui_img_703197322};
const lv_img_dsc_t * ui_imgset_2111622300[1] = {&ui_img_774798805};
const lv_img_dsc_t * ui_imgset_2087311896[1] = {&ui_img_270677314};
const lv_img_dsc_t * ui_imgset_73115368[1] = {&ui_img_1542151835};
const lv_img_dsc_t * ui_imgset_1236677998[1] = {&ui_img_657341686};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void floatout_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_0, 0, 512);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_zoom);
    lv_anim_start(&PropertyAnimation_0);

}
void floatoutlabel_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_Screen1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    ftex = fopen("/mnt/hgfs/ub2004sf/AISmart/UBSDL-lvgl/AiSmart/SimuTalk-copy.txt", "r");

    InitEmojiAutoChange(e);
    InitSowTimeDate(e);
    
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        printf("进入定时器\n");
        InitScreenAutoChangeEmoji(e);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        printf("暂停定时器\n");
        lv_timer_pause(emoji_timer);
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Screen2_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_UNLOADED) {
        printf("删除定时器\n");
        lv_timer_del(emoji_timer);
        InitUnLoad(e);
    }
    if(event_code == LV_EVENT_CLICKED) {
        printf("暂停定时器\n");
        lv_timer_pause(emoji_timer);
        _ui_flag_modify(ui_time, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_date, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        printf("暂停定时器\n");
        lv_timer_pause(emoji_timer);
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Screen4, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_Screen4_screen_init);
    }
}
void ui_event_time(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        floatoutlabel_Animation(ui_time, 0);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_time, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_date(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        floatoutlabel_Animation(ui_date, 0);
    }
}
void ui_event_Oneto2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen2_screen_init);
    }
}
void ui_event_Oneto4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen3_screen_init);
    }
}
void ui_event_Screen4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Screen2_screen_init);
    }
}
void ui_event_time2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_label_set_property(ui_time, _UI_LABEL_PROPERTY_TEXT, "");
    }
}
void ui_event_date2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_label_set_property(ui_date, _UI_LABEL_PROPERTY_TEXT, "");
    }
}
void ui_event_fourTo2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen2_screen_init);
    }
}
void ui_event_fourTo3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen3_screen_init);
    }
}
void ui_event_Screen2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Screen3_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_to1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_to3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen3_screen_init);
    }
}
void ui_event_Label7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen3_screen_init);
    }
}
void ui_event_humanPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SetLabel(e);
    }
}
void ui_event_Screen3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_Screen2_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        EatWhatRand(e);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Screen5, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Screen5_screen_init);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen2_screen_init);
    }
}
void ui_event_Label6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen2_screen_init);
    }
}
void ui_event_Button7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_Label9(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen2_screen_init);
    }
}
void ui_event_Screen5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_Screen3_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        (e);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen3_screen_init);
    }
}
void ui_event_Label8(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen2_screen_init);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_Label10(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Screen2_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen4_screen_init();
    ui_Screen2_screen_init();
    ui_Screen3_screen_init();
    ui_Screen5_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
