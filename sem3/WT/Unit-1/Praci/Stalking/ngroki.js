"use strict";
window.addEventListener("load", function () {
  var t,
    e,
    n = (
      (function (t) {
        try {
          return JSON.parse(t || "{}");
        } catch (t) {
          return {};
        }
      })(
        (function (t) {
          if (
            /^([0-9a-zA-Z+/]{4})*(([0-9a-zA-Z+/]{2}==)|([0-9a-zA-Z+/]{3}=))?$/.test(
              t
            )
          )
            try {
              return window.atob(t) || "{}";
            } catch (e) {
              return window.decodeURIComponent(t);
            }
          return window.decodeURIComponent(t);
        })(
          ((document.getElementById("root") || {}).dataset || {}).payload || ""
        )
      ).cdnBase ||
      "https://cdn.ngrok.com" ||
      ""
    )
      .trim()
      .replace(/\/+$/, "");
  (t = n + "/static/compiled/js/allerrors.js"),
    (e = document.createElement("script")).setAttribute("src", t),
    document.head.appendChild(e),
    (function (t) {
      var e = document.createElement("link");
      e.setAttribute("rel", "stylesheet"),
        e.setAttribute("type", "text/css"),
        e.setAttribute("href", t),
        document.head.appendChild(e);
    })(n + "/static/compiled/css/allerrors.css");
  var r = document.getElementById("style");
  r && r.remove();
});
