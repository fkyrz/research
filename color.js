function generateColors(count) {
    const colors = [];
    for (let i = 0; i < count; i++) {
        const hue = (i / count) * 360;
        colors.push(hsvToRgb(hue, 1, 1));
    }
    return colors;
}

function hsvToRgb(h, s, v) {
    const f = (n, k = (n + h / 60) % 6) => v - v * s * Math.max(Math.min(k, 4 - k, 1), 0);
    const r = Math.round(f(5) * 255);
    const g = Math.round(f(3) * 255);
    const b = Math.round(f(1) * 255);
    return rgbToHex(r, g, b);
}

function rgbToHex(r, g, b) {
    return '#' + componentToHex(r) + componentToHex(g) + componentToHex(b);
}

function componentToHex(c) {
    const hex = c.toString(16);
    return hex.length === 1 ? '0' + hex : hex;
}

const colors = generateColors(actionData.length);