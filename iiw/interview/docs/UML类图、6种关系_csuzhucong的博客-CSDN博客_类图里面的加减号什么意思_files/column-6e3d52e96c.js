$(function(){function e(){var e=setInterval(function(){if(document.getElementById("csdn-toolbar")){clearInterval(e),d=document.getElementById("csdn-toolbar").offsetHeight;var o=document.documentElement.scrollTop||window.pageYOffset||document.body.scrollTop;o-l>0&&o<a-t&&t>0?n.css({position:"fixed","z-index":"999",left:c+"px",top:d,width:i}):n.css({position:"unset","z-index":"10",left:"0px",top:"0",width:i})}},100)}var o=window.location.href;if(o.indexOf("category_")>-1){var n=$("#column .column_info_box"),a=$("#column .column_article_list").height(),t=$("#column .column_article_list li").length?$("#column .column_article_list li").height():0,s=document.getElementsByTagName("main")[0],c=s.offsetLeft,i=s.offsetWidth,l=document.getElementsByTagName("header")[0].offsetHeight,d=0;e(),$(window).scroll(function(){e()}),$(window).resize(function(){c=s.offsetLeft,i=s.offsetWidth,e()})}}),$(function(){function e(){N="https://csdnimg.cn/release/download/images/pay_error.png",j="已扫码<br>请在手机端操作",$("#payCode").html('<div class="renovate"><img src="'+N+'"><span>'+j+"</span></div>"),$("#payCodeImg").html('<img class="repeat-again" src="'+N+'"><span class="text">'+j+"</span>")}function o(o){var c={goods_id:o,product_id:o,flag:17,request_type:4,is_use_balance:h,coupon_key:C,sale_source:k,success_function:n,error_function:t,timeout_function:s,get_pay_success_callback:a,payment_function:e};$("#payCode").html(z),$("#payCodeImg").html(U),cart.qrPay(c)}function n(e,o){B?d("payCode",o.pay_url):d("payCodeImg",o.pay_url),w=o.pay_url}function a(){I.boxshadow.fadeOut(function(){showToast({text:"支付成功",bottom:"10%",zindex:9e3,speed:500,time:1500}),window.location.reload(),I.payCode.fadeOut(function(){window.location.reload()})})}function t(e){showToast({text:e.errorMessage,bottom:"10%",zindex:9e3,speed:500,time:1500})}function s(){B?I.payCode.find("#payCode").html(E):I.getPay.find("#payCodeImg").html(F)}function c(e,o){var n=Number(e)-Number(o);return n>0?n.toFixed(2):n<0?n.toFixed(2):n}function i(e){$.ajax({type:"GET",url:"https://mall.csdn.net/mp/mallorder/api/internal/goods/getGoodsInfo?goods_id="+e+"&product_id="+e+"&flag=17",xhrFields:{withCredentials:!0},crossDomain:!0,success:function(n){v=n.data.available_amount,n.data.coupon_discount&&n.data.coupon_key&&(_=1*n.data.coupon_discount,C=n.data.coupon_key),S++,S<=1&&(0==v?(h=0,$(".pay-code-radio").prop("disabled",!0)):c(P,_)>0?(h=1,$(".pay-code-radio").attr("data-flag","true"),$(".pay-code-radio").prop("checked",!0)):(h=0,$(".pay-code-radio").prop("disabled",!0))),$(".pay-balance .balance").text(v),$(".pay-code-balance .balance").text(v),l(),o(e)}})}function l(){$(".subscribe-available-balance .subscribe-available-balance-t").css({display:"block"}),_?(c(P,_)>0?h?(c(c(P,_),v)>0?($(".available-balance-0").text("¥"+v),$(".available-balance-1").text("¥"+c(c(P,_),v))):($(".available-balance-0").text("¥"+c(P,_)),$(".available-balance-1").text("¥0")),$(".subscribe-price-box").css({display:"none"}),$(".subscribe-available-balance").css({display:"block"})):($(".available-balance-1").text("¥"+c(P,_)),$(".subscribe-price-box").css({display:"none"}),$(".subscribe-available-balance .subscribe-available-balance-t").css({display:"none"}),$(".subscribe-available-balance").css({display:"block"})):($(".available-balance-1").text("¥0"),$(".subscribe-price-box").css({display:"none"}),$(".subscribe-available-balance .subscribe-available-balance-t").css({display:"none"}),$(".subscribe-available-balance").css({display:"block"})),$(".coupons-box .coupons-money").html("¥"+_),$(".coupons-box").fadeIn()):h?(c(P,v)>0?($(".available-balance-0").text("¥"+v),$(".available-balance-1").text("¥"+c(P,v))):($(".available-balance-0").text("¥"+P),$(".available-balance-1").text("¥0")),$(".subscribe-price-box").css({display:"none"}),$(".subscribe-available-balance").css({display:"block"})):($(".now-price").text("¥"+P),$(".subscribe-available-balance").css({display:"none"}),$(".subscribe-price-box").css({display:"block"}))}function d(e,o){var n=qrcode(6,"M");n.addData(o),n.make(),$("#"+e).html(n.createImgTag(3,3)),$("#"+e).html($("#"+e).html()),B&&I.boxshadow.fadeIn(function(){I.payCode.fadeIn()})}function u(e){if("popup"==e)window.csdn&&window.csdn.userOrderTip&&window.csdn.userOrderTip.show({tabs:["superVipForPopup"]});else{var o=document.createElement("a");o.style.display="none",o.href="https://mall.csdn.net/vip?vipSource=learningVip",o.target="_blank",document.body.appendChild(o),o.click(),document.body.removeChild(o)}}function r(){$.ajax({type:"GET",url:blogUrl+"phoenix/web/get-column-student-ab-test",dataType:"json",xhrFields:{withCredentials:!0},success:function(e){u(200==e.code?e.data:"control")},error:function(e){u("control")}})}function p(){var e=$(this),o=e.data("id");if(e.data("type"))var n=blogUrl+"phoenix/web/v1/subscribe/un-subscribe-study?columnId="+o;else var n=blogUrl+"phoenix/web/v1/subscribe/subscribe-study?columnId="+o;getCookie("UserName")?$.ajax({url:n,type:"post",dataType:"json",xhrFields:{withCredentials:!0},success:function(o){200==o.code&&o.data.status?e.data("type")?O.indexOf("/article/details/")>-1?(e.parents(".column-group-item").find(".studyvip-unsubscribe").css("display","inline-block"),e.parents(".column-group-item").find(".studyvip-subscribe").css("display","none")):($(".studyvip-unsubscribe").css("display","inline-block"),$(".studyvip-subscribe").css("display","none")):O.indexOf("/article/details/")>-1?(e.parents(".column-group-item").find(".studyvip-subscribe").css("display","inline-block"),e.parents(".column-group-item").find(".studyvip-unsubscribe").css("display","none")):($(".studyvip-subscribe").css("display","inline-block"),$(".studyvip-unsubscribe").css("display","none")):showToast({text:o.data.msg||"操作失败，请重试！",bottom:"10%",zindex:9e3,speed:500,time:1500})},error:function(e){showToast({text:e.data.msg||"操作失败，请重试！",bottom:"10%",zindex:9e3,speed:500,time:1500})}}):window.csdn.loginBox.show()}function b(e){var o=new RegExp("(^|&)"+e+"=([^&]*)(&|$)","i"),n=window.location.search.substr(1).match(o);return null!=n?unescape(n[2]):""}function m(e){window.csdn&&window.csdn.userOrderPayment&&window.csdn.userOrderPayment.show({params:[{flag:17,goodsId:e,productId:e}]})}function f(e,o){if(e.show){var n='<div class="column_coupon_main '+(e.receive?"active":"")+'">                <img class="column_coupon_icon" src="'+e.activityIcon+'" alt="">                <div class="column_coupon_text">                <span class="column_coupon_l">'+e.couponDesc+'</span>                <span class="column_coupon_m"></span>                <span class="column_coupon_r" data-couponId="'+e.groupNumber+'" data-columnId="'+o+'">'+(e.receive?"已领取":"立即领取")+"</span>                </div>            </div>";I.columnCouponBox.html(n),I.columnCouponBox.css({display:"flex"})}}function y(e,o,n){$.ajax({type:"GET",url:blogUrl+e,dataType:"json",xhrFields:{withCredentials:!0},data:{columnId:n},success:function(e){200==e.code?f(e.data,n):o.remove()},error:function(e){o.remove()}})}function g(e,o,n){$.ajax({type:"GET",url:blogUrl+e,dataType:"json",xhrFields:{withCredentials:!0},data:{columnId:n},success:function(a){200==a.code?a.data?(o.find(".column_coupon_main").addClass("active"),o.find(".column_coupon_r").html("已领取"),B?m(n):i(n)):setTimeout(function(){g(e,o,n)},500):showToast({text:a.message||"操作失败，请重试！",bottom:"10%",zindex:9e3,speed:500,time:1500})},error:function(e){showToast({text:e.message||"操作失败，请重试！",bottom:"10%",zindex:9e3,speed:500,time:1500})}})}function x(e,o,n){$.ajax({url:blogUrl+e,type:"post",dataType:"json",data:{columnId:n,groupNumber:o},xhrFields:{withCredentials:!0},success:function(e){200==e.code&&e.data?g(I.columnCouponStatus,I.columnCouponBox,n):showToast({text:e.message||"操作失败，请重试！",bottom:"10%",zindex:9e3,speed:500,time:1500})},error:function(e){showToast({text:e.message||"操作失败，请重试！",bottom:"10%",zindex:9e3,speed:500,time:1500})}})}var h=0,v=0,w="",C="",_=0,k="";$(document).on("click",".tip-subscribe-column>span",function(){$(this).parent().find(".tip").fadeIn()}),$(document).on("click",".tip-subscribe-column .bt-close",function(){$(".tip-subscribe-column").find(".tip").fadeOut()});var T="",I={boxshadow:$(".skin-boxshadow"),btClose:$(".bt-close"),payCode:$(".pay-code"),btSubscribe:$(".bt-subscribe-article"),btSubscribeColumn:$(".bt-subscribe-text"),getPay:$(".get-pay"),columnCouponBox:$("#columnCouponBox"),columnCouponCheck:"phoenix/web/v1/coupon/check-column-coupon",columnCouponStatus:"phoenix/web/v1/coupon/get-column-coupon-status",columnCouponLook:"phoenix/web/v1/coupon/get-column-coupon"},B=!1,O=window.location.href;O.indexOf("category_")>-1&&(I.columnCouponBox.length&&(T=I.columnCouponBox.data("id"),y(I.columnCouponCheck,I.columnCouponBox,T)),I.getPay.length&&(B=!1,T=I.getPay.data("id"),getCookie("UserName")&&(k=b("sale_source"),i(T)))),O.indexOf("/article/details/")>-1&&I.columnCouponBox.length&&(B=!0,T=I.columnCouponBox.data("id"),y(I.columnCouponCheck,I.columnCouponBox,T)),$(document).on("click",".bt-subscribe",function(){getCookie("UserName")||window.csdn.loginBox.show()}),I.getPay.on("click",function(){B=!1,T=$(this).data("id"),o(T)}),I.payCode.on("click",".renovate",function(){o(T||$(this).parent().data("id"))}),I.btClose.on("click",function(){I.payCode.fadeOut(function(){I.boxshadow.fadeOut()})});var N=blogStaticHost+"dist/pc/img/pay-time-out.png",j="获取中",U='<img class="repeat-again" src="'+N+'"><span class="text">'+j+"</span>",z='<div class="renov-men"><img src="'+N+'"><span>'+j+"</span></div>",E='<div class="renovate">    <img src="'+blogStaticHost+'dist/pc/img/pay-time-out.png">    <span>点击重新获取</span></div>',F='<img class="repeat-again" src="'+blogStaticHost+'dist/pc/img/pay-time-out.png"><span class="text">点击重新获取</span>';$(".now-price").text();$(".pay-code-radio").click(function(){var e=$(this).attr("data-flag");"true"==e?(h=0,$(this).attr("data-flag","false"),$(this).prop("checked",!1)):(h=1,$(this).attr("data-flag","true"),$(this).prop("checked",!0)),i(T)});var P=$(".subscribe-price .now-price").text().slice(1),S=0;I.payCode.on("click",".blance-bt",function(){window.open(w)}),$(document).on("click",".articleColumnBt",function(){if(getCookie("UserName")){var e=$(this).data("id");m(e)}else window.csdn.loginBox.show({spm:"1001.2101.3001.8610"})}),$(document).on("click",".column-studyvip-pass",function(){getCookie("UserName")?r():window.csdn.loginBox.show()}),$(document).on("click",".column-studyvip-ajax",p),$(document).on("click","#columnCouponBox",function(e){if(getCookie("UserName")){if("column_coupon_r"==e.target.className&&!$(this).find(".column_coupon_main").hasClass("active")){var o=e.target.dataset.couponid,n=e.target.dataset.columnid;x(I.columnCouponLook,o,n)}}else window.csdn.loginBox.show()})});