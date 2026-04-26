const fs = require('fs');
const path = require('path');

function checkFileExists(filePath) {
    if (!fs.existsSync(filePath)) {
        console.error(`Error: File ${filePath} not found.`);
        process.exit(1);
    }
}

function checkContent(filePath, pattern, description) {
    const content = fs.readFileSync(filePath, 'utf8');
    if (!pattern.test(content)) {
        console.error(`Error: ${description} not found in ${filePath}.`);
        process.exit(1);
    }
}

console.log("Running Performance Analysis Unit Tests...");

// 1. Check for profiling logic
checkFileExists('src/main.ino');
checkFileExists('src/SystemProfiler.cpp');
checkContent('src/SystemProfiler.cpp', /micros\(\)/, "Performance timing (micros())");
checkContent('src/main.ino', /startProfile|endProfile/, "Profiling markers");

// 2. Check for Protocol Optimization
checkFileExists('include/protocol_v2.h');
checkContent('include/protocol_v2.h', /sprintf|encode/, "Protocol encoding logic");
checkContent('include/protocol_v2.h', /vS|A|T/, "Compact protocol markers");

// 3. Check for Canvas Optimization
checkFileExists('web/js/high_speed_canvas.js');
checkContent('web/js/high_speed_canvas.js', /requestAnimationFrame/, "UI rendering optimization");
checkContent('web/js/high_speed_canvas.js', /OffscreenCanvas|bgCanvas|drawImage/, "Canvas buffering/caching");

// 4. Check for Performance Report
checkFileExists('docs/profiling_report.md');
checkContent('docs/profiling_report.md', /Loop Time|FPS|Frequency/, "Performance metrics in report");

console.log("All performance unit tests passed!");
