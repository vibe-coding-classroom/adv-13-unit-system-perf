/**
 * @file high_speed_canvas.js
 * @brief High-performance UI rendering using Offscreen Canvas and requestAnimationFrame.
 */

class FastDashboard {
    constructor(canvasId) {
        this.canvas = document.getElementById(canvasId);
        this.ctx = this.canvas.getContext('2d');
        
        // Offscreen canvas for static background
        this.bgCanvas = document.createElement('canvas');
        this.bgCtx = this.bgCanvas.getContext('2d');
        
        this.width = this.canvas.width;
        this.height = this.canvas.height;
        this.bgCanvas.width = this.width;
        this.bgCanvas.height = this.height;

        this.dataPoints = [];
        this.maxDataPoints = 100;
        
        this.initBackground();
        this.render();
    }

    initBackground() {
        // Draw static grid and labels only once
        this.bgCtx.strokeStyle = 'rgba(255, 255, 255, 0.1)';
        this.bgCtx.lineWidth = 1;
        for (let i = 0; i < this.width; i += 50) {
            this.bgCtx.beginPath();
            this.bgCtx.moveTo(i, 0);
            this.bgCtx.lineTo(i, this.height);
            this.bgCtx.stroke();
        }
        for (let j = 0; j < this.height; j += 50) {
            this.bgCtx.beginPath();
            this.bgCtx.moveTo(0, j);
            this.bgCtx.lineTo(this.width, j);
            this.bgCtx.stroke();
        }
    }

    addDataPoint(val) {
        this.dataPoints.push(val);
        if (this.dataPoints.length > this.maxDataPoints) {
            this.dataPoints.shift();
        }
    }

    render() {
        // Optimization: requestAnimationFrame for smooth 60fps
        requestAnimationFrame(() => this.render());

        // 1. Clear main canvas
        this.ctx.clearRect(0, 0, this.width, this.height);

        // 2. Draw static background from cache
        this.ctx.drawImage(this.bgCanvas, 0, 0);

        // 3. Draw dynamic waveform
        if (this.dataPoints.length < 2) return;

        this.ctx.beginPath();
        this.ctx.strokeStyle = '#00ffcc';
        this.ctx.lineWidth = 2;
        this.ctx.shadowBlur = 10;
        this.ctx.shadowColor = '#00ffcc';

        const step = this.width / (this.maxDataPoints - 1);
        for (let i = 0; i < this.dataPoints.length; i++) {
            const x = i * step;
            const y = this.height - (this.dataPoints[i] + 100) * (this.height / 200);
            if (i === 0) this.ctx.moveTo(x, y);
            else this.ctx.lineTo(x, y);
        }
        this.ctx.stroke();
        this.ctx.shadowBlur = 0; // Reset for next elements
    }
}

// Usage:
// const dashboard = new FastDashboard('myCanvas');
// setInterval(() => dashboard.addDataPoint(Math.random() * 200 - 100), 10);
