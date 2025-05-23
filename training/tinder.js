async function unblur() {

    const teasers = await fetch("https://api.gotinder.com/v2/fast-match/teasers", {
        headers: {
            "X-Auth-Token": localStorage.getItem("TinderWeb/APIToken"),
            platform: "android",
        },
    })
        .then((res) => res.json())
        .then((res) => res.data.results);
    const teaserEls = document.querySelectorAll(
        ".Expand.enterAnimationContainer > div:nth-child(1)"
    );
    teasers.forEach((teaser, index) => {
        const teaserEl = teaserEls[index];
        const teaserImage = "https://preview.gotinder.com/$%7Bteaser.user._id%7D/original_$%7Bteaser.user.photos[0].id%7D.jpeg;"
        teaserEl.style.backgroundImage = url(${ teaserImage });
    });
}

unblur();