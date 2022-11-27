using KarmoBlazorServerDB.Data.KarmoBlazorServer;
using Microsoft.EntityFrameworkCore;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace KarmoBlazorServer.Data
{
    public class TempService
    {
        private readonly KarmoAppContext _context;

        public TempService(KarmoAppContext context)
        {
            _context = context;
        }

        public async Task<List<Temp>> GetTempAsync(string tempName)
        {
            // Get Weather Forecasts
            return await _context.Temp
            // Only get entries for the current logged in user
            .Where(x => x.Name == tempName)
            // Use AsNoTracking to disable EF change tracking
            // Use ToListAsync to avoid blocking a thread
            .AsNoTracking().ToListAsync();
        }

        public Task<Temp> CreateForecastAsync(Temp objTemp)
        {
            _context.Temp.Add(objTemp);
            _context.SaveChanges();
            return Task.FromResult(objTemp);
        }

        public Task<bool> UpdateForecastAsync(Temp objTemp)
        {
            var ExistingTemp = _context.Temp.Where(x => x.Id == objTemp.Id).FirstOrDefault();
            if (ExistingTemp != null)
            {
                ExistingTemp.Name = objTemp.Name;
                _context.SaveChanges();
            }
            else
            {
                return Task.FromResult(false);
            }
            return Task.FromResult(true);
        }

        public Task<bool> DeleteForecastAsync(Temp objTemp)
        {
            var ExistingTemp = _context.Temp.Where(x => x.Id == objTemp.Id).FirstOrDefault();
            if (ExistingTemp != null)
            {
                _context.Temp.Remove(ExistingTemp);
                _context.SaveChanges();
            }
            else
            {
                return Task.FromResult(false);
            }
            return Task.FromResult(true);
        }
    }
}