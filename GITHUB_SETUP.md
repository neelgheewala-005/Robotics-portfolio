# GitHub Setup Instructions for Your Portfolio

## Step 1: Create a New Repository on GitHub

1. Go to **https://github.com/new** (or click "+" → "New repository")
2. Fill in the details:
   - **Repository name:** `robotics-portfolio` (or `claude_project`)
   - **Description:** "Robotics Engineering Portfolio - KUKA, Machine Vision, Embedded Systems"
   - **Public** (so it's accessible as a portfolio)
   - **DO NOT** initialize with README (we already have one)
   - **DO NOT** add .gitignore (we already have one)
   - Click **Create repository**

## Step 2: Connect Local Repository to GitHub

After creating the repository, GitHub will show you commands. Run these in your terminal:

```bash
cd C:\Users\Prachi\Desktop\claude_project
git branch -M main
git remote add origin https://github.com/neelgheewala-005/robotics-portfolio.git
git push -u origin main
```

**Replace** `robotics-portfolio` with your actual repository name if different.

## Step 3: Verify Push Was Successful

- Go to your repository on GitHub: https://github.com/neelgheewala-005/robotics-portfolio
- You should see all your files there

## Step 4: Enable GitHub Pages (Optional but Recommended)

To make your portfolio accessible as a live website:

1. Go to repository **Settings** → **Pages**
2. Under "Build and deployment":
   - **Source:** Deploy from a branch
   - **Branch:** `main` / `/(root)`
3. Click **Save**
4. Wait 1-2 minutes for deployment
5. Your site will be live at: `https://neelgheewala-005.github.io/robotics-portfolio/`

---

## Quick Command Reference

```bash
# Navigate to project
cd C:\Users\Prachi\Desktop\claude_project

# Check git status
git status

# Make changes and commit
git add .
git commit -m "Your message here"

# Push to GitHub
git push

# Pull updates from GitHub
git pull

# View commit history
git log --oneline
```

---

## Current Project Structure

```
robotics-portfolio/
├── portfolio/
│   ├── index.html                          ✓ Main website
│   ├── Lebenslauf_Neel_Gheewala.pdf       ✓ Your CV
│   └── kuka_frame.rdk                      ✓ KUKA project file
├── IMG_20260319_001332_edit_311779287606428.jpg  ✓ Profile image
├── README.md                               ✓ Documentation
├── .gitignore                              ✓ Git configuration
└── .git/                                   ✓ Local repository

```

---

## What's Included in Your Portfolio

✅ **Project 1: KUKA Robot Simulation**
   - Download button for RoboDK file
   - Project details and achievements

✅ **Project 2: Vision-Based Pick & Place**
   - Full MATLAB code snippet
   - Image processing implementation

✅ **Project 3: Autonomous Line Follower**
   - Arduino/AVR C code
   - Control system details
   - Sensor integration info

✅ **Profile Section**
   - Your actual profile photo
   - Professional biography
   - Current focus and seeking information

✅ **CV Download**
   - Direct download of Lebenslauf_Neel_Gheewala.pdf
   - Integrated in Download CV button

✅ **Education & Skills**
   - Full academic details
   - Coursework listing
   - Technical specializations

✅ **Social Links**
   - LinkedIn integration
   - Email contact
   - Phone contact

---

## Next Steps

1. **Create the GitHub repository** using the link above
2. **Run the push commands** to upload your project
3. **Enable GitHub Pages** for live hosting
4. **Share your portfolio** URL with employers/internship programs

Your portfolio URL will be:
- GitHub Repo: `https://github.com/neelgheewala-005/robotics-portfolio`
- Live Site: `https://neelgheewala-005.github.io/robotics-portfolio/`

---

## Troubleshooting

**If you get "Permission denied" error:**
- Make sure you're authenticated with GitHub
- On Windows, use: `git config --global user.name "Your Name"` and `git config --global user.email "your@email.com"`

**If push fails:**
- Check your internet connection
- Verify repository name is correct
- Ensure you have write permissions to the repository

---

**Created:** November 15, 2026
**Next Update:** Ready when you make changes to projects!
