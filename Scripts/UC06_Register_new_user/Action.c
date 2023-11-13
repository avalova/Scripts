Action()
{
	lr_start_transaction("UC06_WelcomePage");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);

	web_url("webtours_2", 
		"URL=http://{host}/webtours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html_2", 
		"URL=http://{host}/webtours/header.html", 
		"Resource=0", 
		"Referer=http://{host}/webtours/", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("welcome.pl_2", 
		"URL=http://{host}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/webtours/", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html_2", 
		"URL=http://{host}/WebTours/home.html", 
		"Resource=0", 
		"Referer=http://{host}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL=http://{host}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t13.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC06_WelcomePage",LR_AUTO);

	lr_start_transaction("UC06_Sign_up");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(5);

	web_url("login.pl", 
		"URL=http://{host}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/WebTours/home.html", 
		"Snapshot=t14.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("profileValidate.js", 
		"URL=http://{host}/WebTours/profileValidate.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=http://{host}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t15.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("button_next.gif", 
		"URL=http://{host}/WebTours/images/button_next.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t16.inf", 
		LAST);

	lr_end_transaction("UC06_Sign_up",LR_AUTO);

	lr_start_transaction("UC06_Send_userdata");
	
	web_add_header("Origin", 
		"http://{host}");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);	

	lr_save_string(lr_eval_string("user{unNum}name"),"username" );
	

	web_reg_find("Fail=NotFound",
		"Text=Thank you",
		LAST);

	web_submit_data("login.pl_2", 
		"Action=http://{host}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t17.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value=qqq", ENDITEM, 
		"Name=passwordConfirm", "Value=qqq", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=address", ENDITEM, 
		"Name=address2", "Value=address", ENDITEM, 
		"Name=register.x", "Value=62", ENDITEM, 
		"Name=register.y", "Value=8", ENDITEM, 
		LAST);
/*	
		web_submit_data("login.pl_2", 
		"Action=http://{host}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t17.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=username", "Value={username1}", ENDITEM, 
		"Name=password", "Value={password1}", ENDITEM, 
		"Name=passwordConfirm", "Value={password1}", ENDITEM, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=register.x", "Value=62", ENDITEM, 
		"Name=register.y", "Value=8", ENDITEM, 
		LAST);
*/
	lr_end_transaction("UC06_Send_userdata",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC06_continuie");

	web_url("button_next.gif_2", 
		"URL=http://{host}/cgi-bin/welcome.pl?page=menus", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/login.pl", 
		"Snapshot=t18.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_url("login.pl_3", 
		"URL=http://{host}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t19.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t20.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("itinerary.gif", 
		"URL=http://{host}/WebTours/images/itinerary.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t21.inf", 
		LAST);

	web_url("flights.gif", 
		"URL=http://{host}/WebTours/images/flights.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t22.inf", 
		LAST);

	web_url("in_home.gif", 
		"URL=http://{host}/WebTours/images/in_home.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t23.inf", 
		LAST);

	web_url("signoff.gif", 
		"URL=http://{host}/WebTours/images/signoff.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t24.inf", 
		LAST);

	lr_end_transaction("UC06_continuie",LR_AUTO);

	lr_start_transaction("UC06_Logout");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);

	web_url("SignOff Button", 
		"URL=http://{host}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t25.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html_3", 
		"URL=http://{host}/WebTours/home.html", 
		"Resource=0", 
		"Referer=http://{host}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t26.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_4", 
		"URL=http://{host}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t27.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC06_Logout",LR_AUTO);

	return 0;
}