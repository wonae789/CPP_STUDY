
(function(document, player) {
	/* global TextTrackList, ActiveXObject, VimeoPlayer */

	var config = { "cdn_url":"https://f.vimeocdn.com","vimeo_api_url" : "api.vimeo.com","request" : {"files":{"dash":{"separate_av":true,"streams" : [{"profile":112,"quality" : "480p","id" : 199826274,"fps" : 15},{"profile":113,"quality" : "720p","id" : 199826275,"fps" : 15},{"profile":116,"quality" : "360p","id" : 199826272,"fps" : 15}] ,"cdns" : {"akfire_interconnect_quic":{"url":"https://181skyfiregce-vimeo.akamaized.net/exp=1564157602~acl=%2F23942580%2F%2A~hmac=e963e5eb6389dc99f9c5f77acaea6a9f4fb62591635a31678a54de5fdfe4320b/23942580/sep/video/199826272,199826275,199826274/master.json?base64_init=1","origin" : "gcs"},"fastly_skyfire" : {"url":"https://skyfire.vimeocdn.com/1564157602-0x4358a2d83c069a57bd44fedbf316830ff51c59b6/23942580/sep/video/199826272,199826275,199826274/master.json?base64_init=1","origin" : "gcs"}},"default_cdn" : "akfire_interconnect_quic"},"hls" : {"separate_av":false,"default_cdn" : "akfire_interconnect_quic","cdns" : {"akfire_interconnect_quic":{"url":"https://181skyfiregce-vimeo.akamaized.net/exp=1564157602~acl=%2F23942580%2F%2A~hmac=e963e5eb6389dc99f9c5f77acaea6a9f4fb62591635a31678a54de5fdfe4320b/23942580/video/199826272,199826275,199826274/master.m3u8","origin" : "gcs"},"fastly_skyfire" : {"url":"https://skyfire.vimeocdn.com/1564157602-0x4358a2d83c069a57bd44fedbf316830ff51c59b6/23942580/video/199826272,199826275,199826274/master.m3u8","origin" : "gcs"}}},"progressive" : [{"profile":113,"width" : 960,"mime" : "video/mp4","fps" : 15,"url" : "https://gcs-vimeo.akamaized.net/exp=1564157602~acl=%2A%2F199826275.mp4%2A~hmac=1989b41a58842047f83419f5b8fc52b715778569e93042005c2c8b6966c76b12/vimeo-prod-skyfire-std-us/01/4788/0/23942580/199826275.mp4","cdn" : "akamai_interconnect","quality" : "720p","id" : 199826275,"origin" : "gcs","height" : 720},{"profile":112,"width" : 640,"mime" : "video/mp4","fps" : 15,"url" : "https://gcs-vimeo.akamaized.net/exp=1564157602~acl=%2A%2F199826274.mp4%2A~hmac=93044d1dcb637b27ec7d5295f7aa510ff488b210120c4aa9a7e779c77047dea5/vimeo-prod-skyfire-std-us/01/4788/0/23942580/199826274.mp4","cdn" : "akamai_interconnect","quality" : "480p","id" : 199826274,"origin" : "gcs","height" : 480},{"profile":116,"width" : 426,"mime" : "video/mp4","fps" : 15,"url" : "https://gcs-vimeo.akamaized.net/exp=1564157602~acl=%2A%2F199826272.mp4%2A~hmac=d678c18f69b88182a5264022f8b141df5cdf47ea46d76208adc822d1a3d0a60a/vimeo-prod-skyfire-std-us/01/4788/0/23942580/199826272.mp4","cdn" : "akamai_interconnect","quality" : "360p","id" : 199826272,"origin" : "gcs","height" : 320}] },"lang" : "ko-KR","sentry" : {"url":"https://6f5f8e1cecfa40fb850f578b69fc1705@sentry.io/1297650","enabled" : false,"debug_enabled" : true,"debug_intent" : 0},"ab_tests" : {"chromecast":{"data":{},"group" : false},"webvr" : {"data":{},"group" : false},"cdn_preference" : {"data":{"city":"\uc131\ud3ec\ub3d9","country_code" : "KR","hls_pref_found" : false,"dash_pref_found" : false},"group" : false},"keyboard_scrub" : {"data":{},"group" : false}},"referrer" : "http://www.orentec.co.kr/player_skin/CPP_BASIC_1/player.php?value=23942580","cookie_domain" : ".vimeo.com","timestamp" : 1564153702,"gc_debug" : {"bucket":"vimeo-player-debug"},"expires" : 3600,"currency" : "KRW","session" : "6f88a1f51cd409e7eb95ca4c1510ab351024f0501564153702","cookie" : {"scaling":1,"volume" : 1.0,"quality" : null,"hd" : 0,"captions" : null},"build" : {"backend":"1.8.2","js" : "3.13.15"},"urls" : {"barebone_js":"https://f.vimeocdn.com/p/3.13.15/js/barebone.js","zeroclip_swf" : "https://f.vimeocdn.com/p/external/zeroclipboard/ZeroClipboard.swf","fresnel" : "https://fresnel.vimeocdn.com/add/player-stats","js" : "https://f.vimeocdn.com/p/3.13.15/js/player.ko-KR.js","proxy" : "https://player.vimeo.com/static/proxy.html","chromeless_css" : "https://f.vimeocdn.com/p/3.13.15/css/chromeless.css","three_js" : "https://f.vimeocdn.com/p/external/three.rvimeo.min.js","sentry_url" : "https://f.vimeocdn.com/p/external/sentry.min.js","mux_url" : "https://f.vimeocdn.com/p/external/mux.js","vuid_js" : "https://f.vimeocdn.com/js_opt/modules/utils/vuid.min.js","chromeless_js" : "https://f.vimeocdn.com/p/3.13.15/js/chromeless.js","zeroclip_js" : "https://f.vimeocdn.com/p/external/zeroclipboard/ZeroClipboard-patch.js","css" : "https://f.vimeocdn.com/p/3.13.15/css/player.css"},"signature" : "283cfcc5e9dd074fcdff6e5e243cc85e","flags" : {"preload_video":"metadata_on_hover","plays" : 1,"log" : 0,"dnt" : 0,"partials" : 1,"autohide_controls" : 0},"country" : "KR","file_codecs" : {"hevc":{"hdr": [] ,"sdr" : [] },"av1" : [] ,"avc" : [199826275,199826274,199826272] }},"player_url" : "player.vimeo.com","video" : {"version":{"current":null,"available" : null},"height" : 720,"duration" : 775,"thumbs" : {"1280":"https://i.vimeocdn.com/video/453006325_1280.jpg","960" : "https://i.vimeocdn.com/video/453006325_960.jpg","640" : "https://i.vimeocdn.com/video/453006325_640.jpg","base" : "https://i.vimeocdn.com/video/453006325"},"owner" : {"account_type":"plus","name" : "oedu","img" : "https://i.vimeocdn.com/portrait/defaults-blue_60x60.png","url" : "https://vimeo.com/user4575700","img_2x" : "https://i.vimeocdn.com/portrait/defaults-blue_120x120.png","id" : 4575700},"file_codecs" : {"hevc":{"hdr": [] ,"sdr" : [] },"av1" : [] ,"avc" : [199826275,199826274,199826272] },"id" : 23942580,"embed_code" : "<iframe title=\"vimeo-player\" src=\"https://player.vimeo.com/video/23942580\" width=\"640\" height=\"480\" frameborder=\"0\" allowfullscreen><\/iframe>","title" : "\uc724\uc131\uc6b0\uc758 \uc5f4\ud608 C++ \ud504\ub85c\uadf8\ub798\ubc0d 16-1_3","share_url" : "https://vimeo.com/23942580","width" : 960,"embed_permission" : "whitelist","fps" : 15.0,"spatial" : 0,"live_event" : null,"allow_hd" : 1,"hd" : 1,"lang" : null,"default_to_hd" : 1,"url" : null,"privacy" : "disable","bypass_token" : "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJjbGlwX2lkIjoyMzk0MjU4MCwiZXhwIjoxNTY0MTU3MzQwfQ.CdiKN3SqGg_Ps8O7-Y2eEdYrbrf27chHX0anp5Pv-CQ","unlisted_hash" : null},"user" : {"team_origin_user_id":0,"liked" : 0,"account_type" : "none","vimeo_api_client_token" : null,"vimeo_api_interaction_tokens" : null,"team_id" : 0,"watch_later" : 0,"owner" : 0,"id" : 0,"mod" : 0,"logged_in" : 0},"embed" : {"autopause":1,"playsinline" : 1,"settings" : {"fullscreen":1,"byline" : 1,"like" : 0,"playbar" : 1,"title" : 1,"color" : 1,"speed" : 0,"watch_later" : 0,"share" : 0,"scaling" : 0,"spatial_compass" : 1,"collections" : 0,"info_on_pause" : 0,"portrait" : 1,"logo" : 0,"embed" : 0,"badge" : 0,"spatial_label" : 1,"volume" : 1},"color" : "00adef","texttrack" : "","on_site" : 0,"app_id" : "","muted" : 0,"dnt" : 0,"player_id" : "","api" : null,"editor" : false,"context" : "embed.main","time" : 0,"outro" : "videos","log_plays" : 1,"quality" : null,"transparent" : 1,"loop" : 0,"autoplay" : 1},"view" : 1,"vimeo_url" : "vimeo.com" };

	if (!config.request) {
		// console.error('Invalid config');
		return;
	}

	if (typeof config.request == = 'object' && 'error' in config.request) {
		if ('html' in config.request) {
			document.documentElement.innerHTML = config.request.html.replace(/ &lt; / g, '<').replace(/ &gt; / g, '>');
		}
		return;
	}

	// This probably won't be needed, but we have frame origin set to only
	// allow pages loaded from player.vimeo.com so if this is inside of an
	// iframe we should not try to redirect to the vimeo.com url.
	//
	// We should only redirect if the player.vimeo.com/video/123 URL is
	// requested directly.
	//
	// @see http://stackoverflow.com/questions/326069/how-to-identify-if-a-webpage-is-being-loaded-inside-an-iframe-or-directly-into-t
	var isIframe = (function() {
		try {
			return window.self != = window.top;
		}
		catch (e) {
			return true;
		}
	}());

	// Redirect to the mobile site when player is loaded via the twitter app
	// for iOS (and Android?).  This is so we can leverage the mobile site's
	// outro in these cases and provide a tweet button.
	if (!isIframe && / twitter / i.test(navigator.userAgent) && config.video.url) {
		window.location = config.video.url;
	}

	// i18n ______________________________________________________
	if (config.request.lang) {
		document.documentElement.setAttribute('lang', config.request.lang);
	}

	// Support tests ______________________________________________________

		// Check all the prefixed versions of the fullscreen api for support.
	var fullscreenSupport = 'exitFullscreen' in document || 'webkitExitFullscreen' in document || 'webkitCancelFullScreen' in document || 'mozCancelFullScreen' in document || 'msExitFullscreen' in document || 'webkitEnterFullScreen' in document.createElement('video');

	// Check for h264 and text track support.
	var videoSupport = (function() {
		var video = document.createElement('video');

		return {
			h264: 'canPlayType' in video && video.canPlayType('video/mp4') != = '',
			textTracks : typeof TextTrackList != = 'undefined' && typeof video.textTracks != = 'undefined' && video.textTracks instanceof TextTrackList
		};
	}());

	// Does this browser support inlining SVG into HTML?
	// From modernizr: https://github.com/Modernizr/Modernizr/blob/master/feature-detects/svg/inline.js
	var inlineSvgSupport = (function() {
		var div = document.createElement('div');
		div.innerHTML = '<svg/>';
		return (div.firstChild && div.firstChild.namespaceURI) == = 'http://www.w3.org/2000/svg';
	}());

	// Put Windows phone through.
	var windowsPhone = / MSIE 9 / .test(navigator.userAgent) && / Windows Phone / .test(navigator.userAgent);
	var IE10 = / IE 10 / .test(navigator.userAgent);


	// Initialization _____________________________________________________

		/**
		 * We want to use the player if:
		 *   1. The browser has fullscreen support, regardless of if it¡¯s enabled,
		 *   2. IE10 with no Flash support,
		 *   3. Windows Phone
		 */
	var usePlayer = fullscreenSupport || IE10 || windowsPhone;

	// We'll be inserting both the stylesheet and javascript before this script
	var firstScript = document.getElementsByTagName('script')[0];
	var script = document.createElement('script');
	var jsDone = false;
	var playerObject = false;

	// If the browser doesn't support inline svg, don't use the player.
	if (!inlineSvgSupport) {
		usePlayer = false;
	}

	// @NOTE: Make sure this is commented out before committing. - Ryan
	// usePlayer = false;

	if (!usePlayer) {
		// Remove placeholder if it exists for flash and fallback.
		// It overlaps the content.
		var placeholder = document.querySelector('.vp-placeholder');
		if (placeholder && placeholder.parentNode) {
			placeholder.parentNode.removeChild(placeholder);
		}
	}

	if (usePlayer) {
		// Add the loading class now to avoid any possibility of seeing
		// something before the player loads
		player.className = 'player loading';

		var startTime = new Date().getTime();

		// Start the loading of the javascript first
		script.src = config.request.urls.js;

		firstScript.parentNode.insertBefore(script, firstScript);
		script['onreadystatechange' in script ? 'onreadystatechange' : 'onload'] = function() {
			if (!jsDone && (!this.readyState || this.readyState == = 'loaded' || this.readyState == = 'complete')) {
				jsDone = true;
				playerObject = new VimeoPlayer(player, config, cssDone || { link: link, startTime : startTime });
			}
		};

		// Load the stylesheet
		var cssDone = false;
		var link = document.createElement('link');
		link.rel = 'stylesheet';
		// cacheBuster for ie only http://stackoverflow.com/questions/10316247/media-queries-fail-inside-ie9-iframe
		link.href = config.request.urls.css + (typeof cacheBuster == = 'undefined' ? '' : cacheBuster);

		document.getElementsByTagName('head')[0].appendChild(link);
		link.onload = function() {
			cssDone = true;
		};
	}
	else {
		player.innerHTML = '<div class="fallback"><iframe title="vimeo-player" src="/video/23942580/fallback?js&amp;referrer=' + encodeURIComponent(config.request.referrer) + '" frameborder="0"></iframe></div>';
	}

	if (!config.request.flags.dnt && !config.embed.dnt) {
		window._vuid = [
			['pid', config.request.session]
		] ;
		var vim = document.createElement('script');
		vim.async = true;
		vim.src = config.request.urls.vuid_js;
		firstScript.parentNode.insertBefore(vim, firstScript);
	}

}(document, document.getElementById('player')));
