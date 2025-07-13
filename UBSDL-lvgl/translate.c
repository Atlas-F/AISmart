Program received signal SIGSEGV, Segmentation fault.
Download failed: 无效的参数.  Continuing without source file ./string/../sysdeps/x86_64/multiarch/strlen-avx2.S.
__strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:76
warning: 76	../sysdeps/x86_64/multiarch/strlen-avx2.S: 没有那个文件或目录
(gdb) bt
#0  __strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:76
#1  0x00005555555d9e4f in CurlRequestStructInit ()
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:129
#2  0x00005555555d8000 in ui_event_Screen2 (e=0x7fffffffd640)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/ui.c:687
#3  0x0000555555587a77 in event_send_core (e=0x7fffffffd640)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:461
#4  0x000055555558680e in lv_event_send (
    obj=0x5555583f7070 <work_mem_int+29104>, 
    event_code=LV_EVENT_STYLE_CHANGED, param=0x0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_event.c:74
#5  0x0000555555566492 in lv_obj_refresh_style (
    obj=0x5555583f7070 <work_mem_int+29104>, selector=0, prop=LV_STYLE_X)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_obj_style.c:187
#6  0x0000555555566780 in lv_obj_set_local_style_prop (
    obj=0x5555583f7070 <work_mem_int+29104>, prop=LV_STYLE_X, value=..., 
    selector=0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lvgl/src/core/lv_obj_style.c:275














    原始API响应: <html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>
<html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>

<API错误: HTTP 400>
原始响应: <html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>
<html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>

<错误：【cJSON_parse】(错误码：0, 详情：Success)>








原始API响应: <html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>

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













===== 完整请求体 =====
Request Body: {"model":"deepseek-chat","max_tokens":2000,"messages":[{"role":"user","content":""}]}
======================
jsonstring = {
	"model":	"deepseek-chat",
	"max_tokens":	2000,
	"messages":	[{
			"role":	"user",
			"content":	""
		}]
}
===== 请求头 =====
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
=================
===== 请求体 =====
{
	"model":	"deepseek-chat",
	"max_tokens":	2000,
	"messages":	[{
			"role":	"user",
			"content":	""
		}]
}
=================
* Host api.deepseek.com:443 was resolved.
* IPv6: (none)
* IPv4: 116.205.40.113, 116.205.40.114
*   Trying 116.205.40.113:443...
* Connected to api.deepseek.com (116.205.40.113) port 443
* ALPN: curl offers h2,http/1.1
*  CAfile: /etc/ssl/certs/ca-certificates.crt
*  CApath: /etc/ssl/certs
* SSL connection using TLSv1.3 / TLS_AES_256_GCM_SHA384 / X25519 / RSASSA-PSS
* ALPN: server accepted http/1.1
* Server certificate:
*  subject: CN=*.deepseek.com
*  start date: Jun  6 00:00:00 2025 GMT
*  expire date: Jun  5 23:59:59 2026 GMT
*  subjectAltName: host "api.deepseek.com" matched cert's "*.deepseek.com"
*  issuer: C=US; O=DigiCert Inc; OU=www.digicert.com; CN=GeoTrust TLS RSA CA G1
*  SSL certificate verify ok.
*   Certificate level 0: Public key type RSA (2048/112 Bits/secBits), signed using sha256WithRSAEncryption
*   Certificate level 1: Public key type RSA (2048/112 Bits/secBits), signed using sha256WithRSAEncryption
*   Certificate level 2: Public key type RSA (2048/112 Bits/secBits), signed using sha256WithRSAEncryption
* using HTTP/1.x
> POST /chat/completions HTTP/1.1
Host: api.deepseek.com
Accept: */*
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Type: application/json
Authorization: Bearer sk-6519dea3fbaa4bb98a7e3682c948afab
Content-Length: 85

* old SSL session ID is stale, removing
< HTTP/1.1 400 Bad Request
< Date: Sun, 13 Jul 2025 06:39:40 GMT
< Content-Type: text/html
< Content-Length: 147
< Connection: close
< Server: CW
<
* Closing connection
原始API响应: <html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>CW</center>
</body>
</html>

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












free(): double free detected in tcache 2

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
    str=str@entry=0x7ffff7bd1bf0 "free(): double free detected in tcache 2")
    at ./malloc/malloc.c:5772
#7  0x00007ffff7aab55f in _int_free (av=0x7ffff7c03ac0 <main_arena>,
    p=<optimized out>, have_lock=0) at ./malloc/malloc.c:4541
#8  0x00007ffff7aaddae in __GI___libc_free (mem=0x5555592c4910)
    at ./malloc/malloc.c:3398
#9  0x00005555555da3c1 in call_deepseek (
    api_key=0x7fffffffedc6 "sk-6519dea3fbaa4bb98a7e3682c948afab",
    prompt=0x555558410800 <input> "hello")
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/AiSmart/depskmainCopy.c:610
#10 0x00005555555db0a9 in deepseek_send_message (session=0x555559392510,
    message=0x555558410800 <input> "hello",
    prompt_tokens=0x555558411088 <prompt_tokens>,
















    *-----------------------------------------*
free(): double free detected in tcache 2

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
    str=str@entry=0x7ffff7bd1bf0 "free(): double free detected in tcache 2")
    at ./malloc/malloc.c:5772
#7  0x00007ffff7aab55f in _int_free (av=0x7ffff7c03ac0 <main_arena>,
    p=<optimized out>, have_lock=0) at ./malloc/malloc.c:4541
#8  0x00007ffff7aaddae in __GI___libc_free (mem=0x5555595ba850)
    at ./malloc/malloc.c:3398
#9  0x00007fffe8528723 in glTexStorageAttribs3DEXT ()
   from /lib/x86_64-linux-gnu/libGLX_mesa.so.0
#10 0x00007fffe8528a58 in glTexStorageAttribs3DEXT ()
   from /lib/x86_64-linux-gnu/libGLX_mesa.so.0
#11 0x00007fffe8528d9b in glTexStorageAttribs3DEXT ()
   from /lib/x86_64-linux-gnu/libGLX_mesa.so.0
#12 0x00007fffe852b781 in glTexStorageAttribs3DEXT ()
   from /lib/x86_64-linux-gnu/libGLX_mesa.so.0
















   free(): double free detected in tcache 2

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
    str=str@entry=0x7ffff7bd1bf0 "free(): double free detected in tcache 2")
    at ./malloc/malloc.c:5772
#7  0x00007ffff7aab55f in _int_free (av=0x7ffff7c03ac0 <main_arena>,
    p=<optimized out>, have_lock=0) at ./malloc/malloc.c:4541
#8  0x00007ffff7aaddae in __GI___libc_free (mem=0x5555595ba850)
    at ./malloc/malloc.c:3398
#9  0x00007fffe8528723 in glTexStorageAttribs3DEXT ()
   from /lib/x86_64-linux-gnu/libGLX_mesa.so.0
#10 0x00007fffe8528a58 in glTexStorageAttribs3DEXT ()
   from /lib/x86_64-linux-gnu/libGLX_mesa.so.0
#11 0x00007fffe8528d9b in glTexStorageAttribs3DEXT ()
   from /lib/x86_64-linux-gnu/libGLX_mesa.so.0
#12 0x00007fffe852b781 in glTexStorageAttribs3DEXT ()
   from /lib/x86_64-linux-gnu/libGLX_mesa.so.0
--Type <RET> for more, q to quit, c to continue without paging--run
#13 0x00007ffff44e5e75 in ?? ()
   from /lib/x86_64-linux-gnu/libgallium-24.2.8-1ubuntu1~24.04.1.so
#14 0x00007ffff44e5f25 in ?? ()
   from /lib/x86_64-linux-gnu/libgallium-24.2.8-1ubuntu1~24.04.1.so
#15 0x00007ffff44e9386 in ?? ()
   from /lib/x86_64-linux-gnu/libgallium-24.2.8-1ubuntu1~24.04.1.so
#16 0x00007ffff45be915 in ?? ()
   from /lib/x86_64-linux-gnu/libgallium-24.2.8-1ubuntu1~24.04.1.so
#17 0x00007ffff45bf865 in ?? ()
   from /lib/x86_64-linux-gnu/libgallium-24.2.8-1ubuntu1~24.04.1.so
#18 0x00007ffff483136e in ?? ()
   from /lib/x86_64-linux-gnu/libgallium-24.2.8-1ubuntu1~24.04.1.so
#19 0x00007ffff45ad791 in ?? ()
   from /lib/x86_64-linux-gnu/libgallium-24.2.8-1ubuntu1~24.04.1.so
#20 0x00007ffff47471d9 in ?? ()
   from /lib/x86_64-linux-gnu/libgallium-24.2.8-1ubuntu1~24.04.1.so
#21 0x00007ffff7e46ac4 in ?? () from /lib/x86_64-linux-gnu/libSDL2-2.0.so.0
#22 0x00007ffff7e39e31 in ?? () from /lib/x86_64-linux-gnu/libSDL2-2.0.so.0
#23 0x00007ffff7e40a28 in ?? () from /lib/x86_64-linux-gnu/libSDL2-2.0.so.0
#24 0x00007ffff7eaf645 in ?? () from /lib/x86_64-linux-gnu/libSDL2-2.0.so.0
#25 0x00007ffff7eb4fd4 in ?? () from /lib/x86_64-linux-gnu/libSDL2-2.0.so.0
#26 0x00007ffff7e4314e in ?? () from /lib/x86_64-linux-gnu/libSDL2-2.0.so.0
#27 0x00005555555d67be in window_update (m=0x5555584101c0 <monitor>)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lv_drivers/sdl/sdl.c:388
#28 0x00005555555d65a3 in monitor_sdl_refr (t=0x0)
    at /mnt/hgfs/FgUb24sharedfolder/AISmart/UBSDL-lvgl/lv_drivers/sdl/sdl.c:313

