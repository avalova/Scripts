Action()
{

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_url("webtours_2", 
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL=http://localhost:1080/webtours/header.html", 
		"Resource=0", 
		"Referer=http://localhost:1080/webtours/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/webtours/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("1_transaction_welcomePage");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(7);

	web_url("webtours_3", 
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html_2", 
		"URL=http://localhost:1080/webtours/header.html", 
		"Resource=0", 
		"Referer=http://localhost:1080/webtours/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/webtours/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_transaction_welcomePage",LR_AUTO);

	lr_start_transaction("1_transaction_login");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(20);

	web_submit_form("login.pl", 
		"Snapshot=t10.inf", 
		ITEMDATA, 
		"Name=username", "Value=Bryan", ENDITEM, 
		"Name=password", "Value=Bryan", ENDITEM, 
		LAST);

	lr_end_transaction("1_transaction_login",LR_AUTO);

	lr_start_transaction("1_transaction_flightPage");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(22);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t11.inf", 
		LAST);

	lr_end_transaction("1_transaction_flightPage",LR_AUTO);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(25);

	web_submit_form("reservations.pl", 
		"Snapshot=t12.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=10/26/2023", ENDITEM, 
		"Name=arrive", "Value=Frankfurt", ENDITEM, 
		"Name=returnDate", "Value=10/27/2023", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_image("Search Flights Button_2", 
		"Alt=Search Flights Button", 
		"Snapshot=t13.inf", 
		LAST);

	lr_start_transaction("1_transaction_sendFlightData");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(6);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t14.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=10/26/2023", ENDITEM, 
		"Name=arrive", "Value=Frankfurt", ENDITEM, 
		"Name=returnDate", "Value=10/27/2023", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	lr_end_transaction("1_transaction_sendFlightData",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("1_transaction_chooseFlight");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t17.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=010;386;10/26/2023", ENDITEM, 
		"Name=reserveFlights.x", "Value=29", ENDITEM, 
		"Name=reserveFlights.y", "Value=0", ENDITEM, 
		LAST);

	lr_end_transaction("1_transaction_chooseFlight",LR_AUTO);

	lr_start_transaction("1_transaction_Payment");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(39);

	web_submit_form("reservations.pl_4", 
		"Snapshot=t18.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Bryan", ENDITEM, 
		"Name=lastName", "Value=Peterson", ENDITEM, 
		"Name=address1", "Value=user2street", ENDITEM, 
		"Name=address2", "Value=5502", ENDITEM, 
		"Name=pass1", "Value=Bryan Peterson", ENDITEM, 
		"Name=creditCard", "Value=23423", ENDITEM, 
		"Name=expDate", "Value=01/24", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("1_transaction_Payment",LR_AUTO);

	lr_start_transaction("1_transactionFlightPage");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(47);

	web_submit_form("reservations.pl_5", 
		"Snapshot=t19.inf", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=69", ENDITEM, 
		"Name=Book Another.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("1_transactionFlightPage",LR_AUTO);

	lr_start_transaction("1_transaction_SignOff");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(13);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t20.inf", 
		LAST);

	lr_end_transaction("1_transaction_SignOff",LR_AUTO);

	return 0;
}