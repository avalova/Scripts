Action()
{	
	lr_start_transaction("1_WelcomePage");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-Site", 
		"none");

	lr_think_time(5);

	web_url("webtours_2", 
		"URL=http://{host}/webtours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

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

	web_concurrent_start(NULL);

	web_url("home.html_2", 
		"URL=http://{host}/WebTours/home.html", 
		"Resource=0", 
		"Referer=http://{host}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		LAST);

/*Correlation comment - Do not change!  Original value='137563.766221142HAHfQDzpccftctffpzVHDf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_url("nav.pl_2", 
		"URL=http://{host}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t13.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("1_WelcomePage",LR_AUTO);

	web_reg_find("Fail=NotFound",
		"Text=User password was correct",
		LAST);

	lr_start_transaction("2_Login");
	
	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(5);

	web_submit_data("login.pl",
		"Action=http://{host}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=http://{host}/cgi-bin/nav.pl?in=home",
		"Snapshot=t14.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=46", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	web_concurrent_start(NULL);

	web_url("login.pl_2", 
		"URL=http://{host}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/login.pl", 
		"Snapshot=t15.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/login.pl", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("itinerary.gif", 
		"URL=http://{host}/WebTours/images/itinerary.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t17.inf", 
		LAST);

	web_url("flights.gif", 
		"URL=http://{host}/WebTours/images/flights.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t18.inf", 
		LAST);

	web_url("in_home.gif", 
		"URL=http://{host}/WebTours/images/in_home.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t19.inf", 
		LAST);

	web_url("signoff.gif", 
		"URL=http://{host}/WebTours/images/signoff.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t20.inf", 
		LAST);

	web_concurrent_end(NULL);
		
	web_add_header("Origin", 
		"http://{host}");

	lr_end_transaction("2_Login",LR_AUTO);
	
	lr_start_transaction("3_Sign_off");

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
		"Snapshot=t46.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Fail=NotFound",
		"Text=Welcome to the Web Tours site.",
		LAST);

	web_url("home.html_2", 
		"URL=http://{host}/WebTours/home.html", 
		"Resource=0", 
		"Referer=http://{host}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t47.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL=http://{host}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t48.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("3_Sign_off",LR_AUTO);

	return 0;
}