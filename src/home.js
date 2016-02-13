$(function () {
    $("#home").show();
    $("#comic").hide();
    buildHome();
});

var pstyle = 'padding: 10px; background: #222222; border: 0;';
var config = {
    layout: {
        name: 'layout',
        panels: [
            { type: 'top', size: 35, resizable: false, style: "padding: 4px; margin: 0" },
            { type: 'left', size: 300, resizable: true, style: pstyle },
            { type: 'main', style: pstyle, content: '' }
        ]
    },
    wtoolbar: {
        name: 'toolbar',
        items: [
            { type: 'button',  id: 'open_comic', caption: 'Open Comic', img: 'icon-folder' },
            { type: 'button',  id: 'add_to_library', caption: 'Add to Library' }
        ]
    },
    wsidebar: {
        name: 'sidebar',
        nodes: [
            {
                id: 'library',
                text: 'Library',
                img: 'icon-folder',
                expanded: true,
                group: true,
                nodes: [ { id: 'all_comics', text: 'All Comics', icon: 'fa-home' },
                       { id: 'recently_added', text: 'Recently Added', icon: 'fa-star' } ]
           }
        ]
    }
};


var buildHome = function() {
    $('#home').w2layout(config.layout);
    w2ui.layout.content('top', $().w2toolbar(config.wtoolbar));
    w2ui.layout.content('left', $().w2sidebar(config.wsidebar));

    $('#home').height(window.innerHeight);
    $(window).resize(function () {
        $('#home').height(window.innerHeight);
    });

};
